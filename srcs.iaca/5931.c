#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int gain, int32_t * vector)
{
  for (i = 0; i < 72; i++)
    {
      int tmp = gain * vector[i] >> 11;
      vector[i] = av_clip_int16_c (tmp);
}}
