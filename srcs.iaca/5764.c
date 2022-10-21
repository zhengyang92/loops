#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const uint8_t aic_quant_matrix[64], int16_t * block, int i, int q)
{
  for (i = 0; i < 64; i++)
     { IACA_START
      int val = (uint16_t) block[i];
      int sign = val & 1;
      block[i] = (((val >> 1) ^ -sign) * q * aic_quant_matrix[i] >> 4) + sign;
} IACA_END }
