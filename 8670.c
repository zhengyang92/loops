#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int temp, int16_t * autocorr, int i, int16_t vector[180],
    const int16_t binomial_window[10], int scale)
{
  for (i = 1; i <= 10; i++)
    {
      temp = ff_dot_product (vector, vector + i, (((60 << 2) / 2) + 60) - i);
      temp =
	(((((temp << scale)) >> 16) * (binomial_window[i - 1]) * 2) +
	 ((((temp << scale)) & 0xffff) * (binomial_window[i - 1]) >> 15));
      autocorr[i] = av_clipl_int32_c ((int64_t) temp + (1 << 15)) >> 16;
    }
}
