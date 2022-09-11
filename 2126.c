#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int ccr1[60], int i, int ccr2[60], int16_t temp_corr[60], int k)
{
  for (k = i; k < 60; k += 2)
    {
      temp_corr[k] = 0;
      ccr2[k] = ccr1[k];
    }
}
