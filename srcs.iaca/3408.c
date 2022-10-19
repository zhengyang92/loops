#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int d, int i, int *deltas, int *Y, int *last, int j,
    unsigned int ct)
{
  for (i = 0; i < 4; i++)
    {
      d = deltas[i + j * 4];
      ct += d;
      last[i] += ct;
      Y[i] = av_clip_uint8_c (last[i]);
    }
}
