#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (const int *coeffs, unsigned int d, int32_t * decoded, int s0, int j,
    unsigned int c, int pred_order)
{
  int s1 = 0;
  for (j = 1; j < pred_order; j++)
    {
      s0 += c * d;
      d = decoded[j];
      s1 += c * d;
      c = coeffs[j];
    }
}
