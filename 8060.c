#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int32_t lpc32[16], int16_t lpc[16], int k, int order)
{
  for (k = 0; k < order; k++)
    {
      int x = (lpc32[k] + 16) >> 5;
      lpc[k] = av_clip_int16_c (x);
      lpc32[k] = lpc[k] << 5;
}}
