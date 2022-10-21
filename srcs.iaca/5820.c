#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (int *coef_idx, const int32_t * quant, int i, int32_t * block,
    int coef_count, const uint8_t * scan)
{
  for (i = 0; i < coef_count; i++)
     { IACA_START
      int idx = coef_idx[i];
      block[scan[idx]] = (block[scan[idx]] * quant[idx]) >> 11;
} IACA_END }
