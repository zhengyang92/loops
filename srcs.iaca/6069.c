#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int16_t int16_t;

int
fn (int16_t impulse_corr[60], const int16_t fixed_cb_gain[24],
    int max_amp_index, int min, int amp, int64_t temp, int j)
{
  for (j = max_amp_index; j >= 2; j--)
    {
      temp =
	av_clipl_int32_c ((int64_t) fixed_cb_gain[j] * impulse_corr[0] << 1);
      temp = ((temp - amp) >= 0 ? (temp - amp) : (-(temp - amp)));
      if (temp < min)
	{
	  min = temp;
	  max_amp_index = j;
	}
    }
}
