#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t samples, int output, const int16_t ff_adpcm_step_table[89],
    const uint8_t size_table[89], uint16_t predict_table[11572],
    uint16_t * dest, int sample, int step_index, GetBitContext gb,
    const int8_t * const step_index_tables[6])
{
  int channels = 1;
  for (sample = 0; sample < samples; sample++)
     { IACA_START
      int lookup_size, lookup, highbit, lowbits;
      step_index = av_clip_c (step_index, 0, 88);
      lookup_size = size_table[step_index];
      lookup = get_bits (&gb, lookup_size);
      highbit = 1 << (lookup_size - 1);
      lowbits = highbit - 1;
      if (lookup & highbit)
	lookup ^= highbit;
      else
	highbit = 0;
      if (lookup == lowbits)
	{
	  output = get_sbits (&gb, 16);
	}
      else
	{
	  int predict_index, diff;
	  predict_index = (lookup << (7 - lookup_size)) | (step_index << 6);
	  predict_index = av_clip_c (predict_index, 0, 5785);
	  diff = predict_table[predict_index];
	  if (lookup)
	    diff += ff_adpcm_step_table[step_index] >> (lookup_size - 1);
	  if (highbit)
	    diff = -diff;
	  output = av_clip_int16_c (output + diff);
	}
      *dest = output;
      dest += channels;
      step_index += step_index_tables[lookup_size - 2][lookup];
     } IACA_END
}
