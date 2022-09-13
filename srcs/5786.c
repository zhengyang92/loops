#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *out, float gamma, float fac, int size, const float *lpc)
{
  for (i = 0; i < size; i++)
    {
      out[i] = lpc[i] * fac;
      fac *= gamma;
    }
}
