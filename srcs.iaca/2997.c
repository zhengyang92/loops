#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *X, int i, int *y, int max_idx, int N)
{
  float xy_norm = 0.0f;
  int phase = 0;
  int y_norm = 0;
  float max_den = 1.0f;
  float max_num = 0.0f;
  for (i = 0; i < N; i++)
    {
      const int ca = 1 ^ ((y[i] == 0) & (phase < 0));
      const int y_new =
	y_norm + 2 * phase * ((y[i]) >= 0 ? (y[i]) : (-(y[i])));
      float xy_new = xy_norm + 1 * phase * ((X[i]) >= 0 ? (X[i]) : (-(X[i])));
      xy_new = xy_new * xy_new;
      if (ca && (max_den * xy_new) > (y_new * max_num))
	{
	  max_den = y_new;
	  max_num = xy_new;
	  max_idx = i;
	}
    }
}
