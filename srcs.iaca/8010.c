#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int8_t int8_t;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (uint8_t * ch_assign, unsigned int out_ch, int32_t * data_32,
    int32_t (*sample_buffer)[8], int is32, unsigned int i, int16_t * data_16,
    uint8_t max_matrix_channel, int32_t lossless_check_data,
    int8_t * output_shift)
{
  for (out_ch = 0; out_ch <= max_matrix_channel; out_ch++)
     { IACA_START
      int mat_ch = ch_assign[out_ch];
      int32_t sample =
	sample_buffer[i][mat_ch] * (1U << output_shift[mat_ch]);
      lossless_check_data ^= (sample & 0xffffff) << mat_ch;
      if (is32)
	*data_32++ = sample * 256U;
      else
	*data_16++ = sample >> 8;
     } IACA_END
}
