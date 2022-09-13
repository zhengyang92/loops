#include <stdint.h>
#include <stdio.h>






int
fn (float postscale, float min, float max, int length, float *buffer)
{
  for (int i = 0; i < length; i++)
    {
      buffer[i] *= postscale;
      buffer[i] = av_clipf_sse (buffer[i], min, max);
}}
