#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int bias, int i, uint8_t * sptr, uint8_t * dptr, int size)
{
  for (i = 0; i < size; i++)
    {
      int val = sptr[i] + bias;
      dptr[i] = av_clip_uint8_c (val);
}}
