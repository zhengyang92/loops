#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float lpc[4])
{
  float tmp = 1.0f;
  for (int i = 0; i < 4; i++)
     { IACA_START
      tmp = .9f * tmp;
      lpc[i] = (lpc[i] * tmp);
} IACA_END }
