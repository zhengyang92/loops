#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int chroma[64], double f, int luma[64])
{
  for (int i = 0; i < 64; i++)
     { IACA_START
      luma[i] = ((1) > (16 * f) ? (1) : (16 * f));
      chroma[i] = ((1) > (16 * f) ? (1) : (16 * f));
} IACA_END }
