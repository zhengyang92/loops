#include <stdint.h>
#include <stdio.h>






int
fn (float *in_prelut[3], float *out_prelut[3])
{
  for (int c = 0; c < 3; c++)
    {
      av_freep (&in_prelut[c]);
      av_freep (&out_prelut[c]);
}}
