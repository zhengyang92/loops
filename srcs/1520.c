#include <stdint.h>
#include <stdio.h>






int
fn (int i, int c_bits, float *lpc, const float *quant_arr, int order,
    double *coef, int *idx)
{
  for (i = 0; i < order; i++)
    {
      idx[i] = quant_array_idx (coef[i], quant_arr, c_bits ? 16 : 8);
      lpc[i] = quant_arr[idx[i]];
    }
}
