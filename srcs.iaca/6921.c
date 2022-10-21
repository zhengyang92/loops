#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int d, int *deltas, int *Y, int ct, int *last, int j)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      d = deltas[i + j * 4];
      ct += d;
      last[i] += ct;
      Y[i] = av_clip_uint8_c (last[i]);
     } IACA_END
}
