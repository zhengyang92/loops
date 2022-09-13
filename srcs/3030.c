#include <stdint.h>
#include <stdio.h>






int
fn (float *X, float err_x, int i, float *Y_orig, float *X_orig,
    const int band_size, float *Y)
{
  float err_y = 0.0f;
  for (i = 0; i < band_size; i++)
    {
      err_x += (X[i] - X_orig[i]) * (X[i] - X_orig[i]);
      if (Y)
	err_y += (Y[i] - Y_orig[i]) * (Y[i] - Y_orig[i]);
    }
}
