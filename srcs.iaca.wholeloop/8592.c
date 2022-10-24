#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __int16_t int16_t;

int
fn (int error_sign, uint32_t * pred, int d, int lpc_quant,
    int16_t * lpc_coefs, unsigned int error_val, int lpc_order, int j)
{
  int val = 0;
  IACA_START for (j = 0; j < lpc_order && (int) (error_val * error_sign) > 0; j++)
    {
      int sign;
      val = d - pred[j];
      sign = sign_only (val) * error_sign;
      lpc_coefs[j] -= sign;
      val *= (unsigned) sign;
      error_val -= (val >> lpc_quant) * (j + 1U);
}IACA_END}
