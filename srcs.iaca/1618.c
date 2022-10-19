#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int avg_gain, int i, int log2_ma_pred_order, int16_t * quant_energy)
{
  for (i = (1 << log2_ma_pred_order) - 1; i > 0; i--)
    {
      avg_gain += quant_energy[i - 1];
      quant_energy[i] = quant_energy[i - 1];
    }
}
