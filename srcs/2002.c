#include <stdint.h>
#include <stdio.h>






int
fn (int i, float gamma, double fac, float *coeff, const float *inbuf)
{
  for (i = 0; i < 10; i++)
    {
      coeff[i] = inbuf[i] * fac;
      fac *= gamma;
    }
}
