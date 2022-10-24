#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * quant_energy, int log2_ma_pred_order, int i, int avg_gain)
{
  IACA_START for (i = (1 << log2_ma_pred_order) - 1; i > 0; i--)
    {
      avg_gain += quant_energy[i - 1];
      quant_energy[i] = quant_energy[i - 1];
     } IACA_END
}
