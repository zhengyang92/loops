#include <stdint.h>
#include <stdio.h>






int
fn (const double *S, double mean, int size)
{
  double offset = 0.0;
  for (int n = 0; n < size; n++)
    {
      const double p = S[n] - mean;
      offset = fmax (offset, fabs (p));
}}
