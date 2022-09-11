#include <stdint.h>
#include <stdio.h>






int
fn (short off, int i, short *buf, short shift)
{
  int ret = 0;
  for (i = 0; i < 124; i++)
    {
      int b = buf[i] - off;
      b = ((b >> (shift - 1)) + 1) >> 1;
      ret += av_clip_c (b, 0, 6);
}}
