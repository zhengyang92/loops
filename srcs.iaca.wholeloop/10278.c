#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (int i, float *output, int k, int n, stbi_uc * data, float stbi__l2h_scale,
    int comp, float stbi__l2h_gamma)
{
  IACA_START for (k = 0; k < n; ++k)
    {
      output[i * comp + k] =
	(float) (pow (data[i * comp + k] / 255.0f, stbi__l2h_gamma) *
		 stbi__l2h_scale);
}IACA_END}
