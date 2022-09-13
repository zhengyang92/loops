#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t odd, int16_t even, int width, int16_t * output,
    int16_t * low, int linesize, int16_t * high)
{
  for (i = 0; i < width; i++)
    {
      even = (low[i] - high[i]) / 2;
      odd = (low[i] + high[i]) / 2;
      output[i] = av_clip_uintp2_c (even, 10);
      output[i + linesize] = av_clip_uintp2_c (odd, 10);
    }
}
