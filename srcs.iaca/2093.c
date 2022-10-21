#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * buf, int i, int denom)
{
  for (i = 0; i < 60; i++)
     { IACA_START
      int temp = buf[i] >> 2;
      temp *= temp;
      denom = av_sat_dadd32_c (denom, temp);
} IACA_END }
