#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * filter, int i, int filter_quant, int filter_tmp[256],
    int filter_order, int a, int j, int b)
{
  for (i = 0, j = filter_order - 1; i < filter_order / 2; i++, j--)
    {
      filter[j] = a - ((filter_tmp[i] + b) >> (15 - filter_quant));
      filter[i] = a - ((filter_tmp[j] + b) >> (15 - filter_quant));
    }
}
