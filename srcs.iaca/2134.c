#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * speech, int n, int subframe_size, int16_t gain_prev, int gain)
{
  for (n = 0; n < subframe_size; n++)
     { IACA_START
      gain_prev = (32358 * gain_prev + 0x4000) >> 15;
      gain_prev = av_clip_int16_c (gain + gain_prev);
      speech[n] = av_clip_int16_c ((speech[n] * gain_prev + 0x2000) >> 14);
     } IACA_END
}
