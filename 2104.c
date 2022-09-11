#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int temp, int i, int16_t * lpc, int16_t vector[10], int j,
    int16_t partial_corr)
{
  for (j = 0; j < i; j++)
    {
      temp = partial_corr * vector[i - j - 1] << 1;
      lpc[j] =
	av_clipl_int32_c ((int64_t) (lpc[j] << 16) - temp + (1 << 15)) >> 16;
    }
}
