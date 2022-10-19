#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (float stbi__h2l_scale_i, int i, float stbi__h2l_gamma_i, int k, int n,
    float *data, int comp, stbi_uc * output)
{
  for (k = 0; k < n; ++k)
    {
      float z =
	(float) pow (data[i * comp + k] * stbi__h2l_scale_i,
		     stbi__h2l_gamma_i) * 255 + 0.5f;
      if (z < 0)
	z = 0;
      if (z > 255)
	z = 255;
      output[i * comp + k] = (stbi_uc) ((int) (z));
}}
