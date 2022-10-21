#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int size, int bias, int i, uint8_t * sptr, uint8_t * dptr)
{
  for (i = 0; i < size; i++)
     { IACA_START
      int val = sptr[i] + bias;
      dptr[i] = av_clip_uint8_c (val);
} IACA_END }
