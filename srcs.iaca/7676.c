#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double qscale, int chroma[64], int luma[64])
{
  for (int i = 0; i < 64; i++)
     { IACA_START
      luma[i] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
      chroma[i] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
} IACA_END }
