#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int32_t scale_factor_mult[15][3])
{
  for (i = 0; i < 15; i++)
    {
      int n, norm;
      n = i + 2;
      norm = ((1L << n) * (1 << 23)) / ((1 << n) - 1);
      scale_factor_mult[i][0] =
	(((int64_t) (norm) *
	  (int64_t) (((int) ((1.0 * 2.0) * (1 << 23) + 0.5)))) >> (23));
      scale_factor_mult[i][1] =
	(((int64_t) (norm) *
	  (int64_t) (((int) ((0.7937005259 * 2.0) * (1 << 23) + 0.5)))) >>
	 (23));
      scale_factor_mult[i][2] =
	(((int64_t) (norm) *
	  (int64_t) (((int) ((0.6299605249 * 2.0) * (1 << 23) + 0.5)))) >>
	 (23));
      do
	{
	}
      while (0);
    }
}
