#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int bias, int i, int32_t noise[72], int size, int tmp)
{
  for (i = 1; i < size; i++)
    {
      tmp = (bias + 32358 * noise[i - 1]) >> 15;
      noise[i] = av_clip_int16_c (tmp);
    }
}
