#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;

int
fn (int i, float *spec, BitstreamContext * bc, int num_specs, float max_quant,
    int word_len, int pos, float scale_factor)
{
  for (i = 0; i < num_specs; i++)
    {
      spec[pos + i] =
	bitstream_read_signed (bc, word_len) * scale_factor * max_quant;
    }
}
