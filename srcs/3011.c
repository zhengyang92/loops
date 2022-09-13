#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (int16_t lpc[16], int32_t lpc32[16], int order, int k)
{
  for (k = 0; k < order; k++)
    {
      int x = (lpc32[k] + 16) >> 5;
      lpc[k] = av_clip_int16_c (x);
      lpc32[k] = lpc[k] << 5;
}}
