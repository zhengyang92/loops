#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int j, int i, int32_t ** subband_samples_hi, float (*input))
{
  for (i = 32; i < 64; i++)
    {
      if ((i - 1) & 2)
	input[i] = -subband_samples_hi[i][j];
      else
	input[i] = subband_samples_hi[i][j];
    }
}
