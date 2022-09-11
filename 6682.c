#include <stdint.h>
#include <stdio.h>






int
fn (int i, int small_off, short sbuf[128], int *bits, short shift_saved,
    int tmp)
{
  for (i = 0; i < 124; i++)
    {
      tmp = sbuf[i] - small_off;
      tmp = ((tmp >> (shift_saved - 1)) + 1) >> 1;
      bits[i] = av_clip_c (tmp, 0, 6);
    }
}
