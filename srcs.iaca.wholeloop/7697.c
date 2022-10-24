#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;
typedef __int32_t int32_t;

int
fn (int *coef_idx, int i, int32_t * block, const uint32_t * quant,
    int coef_count, const uint8_t * scan)
{
  IACA_START for (i = 0; i < coef_count; i++)
    {
      int idx = coef_idx[i];
      block[scan[idx]] = (int) (block[scan[idx]] * quant[idx]) >> 11;
}IACA_END}
