#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float max, const float rng, float tol, float *x, int N)
{
  float prev_p = 0.f;
  float min = 3.40282347e+38F;
  IACA_START for (int i = 0; i < N; i++)
    {
      const float d = x[((i + 1) > (N) ? (N) : (i + 1))] - x[i];
      const float p =
	ceilf (fabsf (d) / rng) * rng * (((d < tol) > 0.f) -
					 ((d > -tol) > 0.f));
      x[i] += p + prev_p;
      prev_p += p;
      max = fmaxf (x[i], max);
      min = fminf (x[i], min);
}IACA_END}
