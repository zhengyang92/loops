#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int error_sign, int d, int lpc_quant, int16_t * lpc_coefs, int error_val,
    int lpc_order, int j, int32_t * pred)
{
  int val = 0;
  IACA_START for (j = 0; j < lpc_order && error_val * error_sign > 0; j++)
    {
      int sign;
      val = d - pred[j];
      sign = sign_only (val) * error_sign;
      lpc_coefs[j] -= sign;
      val *= sign;
      error_val -= (val >> lpc_quant) * (j + 1);
}IACA_END}
