#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t q[9], int order, int k, int32_t p[9], int32_t lpc32[16])
{
  for (k = 0; k < order >> 1; k++)
    {
      int32_t p_tmp = p[k + 1] + p[k];
      int32_t q_tmp = q[k + 1] - q[k];
      lpc32[k] = -q_tmp - p_tmp;
      lpc32[order - k - 1] = q_tmp - p_tmp;
    }
}
