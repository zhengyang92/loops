#include <stdint.h>
#include <stdio.h>






int
fn (const int nb_samples, double *dst, int n, double *ptr)
{
  for (n = 0; n < nb_samples; n++)
    {
      ptr[n] += dst[n];
    }
}
