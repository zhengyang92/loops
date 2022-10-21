#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint32_t uint32_t;

int
fn (int error_sign, int d, uint32_t * pred, int lpc_quant,
    int16_t * lpc_coefs, unsigned int error_val, int lpc_order, int j)
{
  int val = 0;
  for (j = 0; j < lpc_order && (int) (error_val * error_sign) > 0; j++)
     { IACA_START
      int sign;
      val = d - pred[j];
      sign = sign_only (val) * error_sign;
      lpc_coefs[j] -= sign;
      val *= (unsigned) sign;
      error_val -= (val >> lpc_quant) * (j + 1U);
} IACA_END }
