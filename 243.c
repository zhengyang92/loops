#include <stdint.h>
#include <stdio.h>






int
fn (float *lut, int N, int n)
{
  for (n = 0; n < N; n++)
    {
      double x = 2 * ((n / (double) (N - 1))) - 1.;
      lut[n] =
	(1 - fabs (x)) * cos (3.14159265358979323846 * fabs (x)) +
	1. / 3.14159265358979323846 * sin (3.14159265358979323846 * fabs (x));
}}
