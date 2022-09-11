#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t filter_coef[2][10], int16_t * lpc,
    const int16_t postfilter_tbl[2][10], int k)
{
  for (k = 0; k < 10; k++)
    {
      filter_coef[0][k] = (-lpc[k] * postfilter_tbl[0][k] + (1 << 14)) >> 15;
      filter_coef[1][k] = (-lpc[k] * postfilter_tbl[1][k] + (1 << 14)) >> 15;
    }
}
