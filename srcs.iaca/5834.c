#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * output_samples, const uint8_t * buf, int scale[2])
{
  int i = 0;
  for (i = 0; i < 32; i++)
     { IACA_START
      *output_samples++ =
	av_clip_int16_c ((scale[0] * (int8_t) * buf++) >> 5);
      *output_samples++ =
	av_clip_int16_c ((scale[1] * (int8_t) * buf++) >> 5);
     } IACA_END
}
