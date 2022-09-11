#include <stdint.h>
#include <stdio.h>






int
fn (int k, float *z)
{
  for (k = 0; k < 64; k++)
    {
      float f = z[k] + z[k + 64] + z[k + 128] + z[k + 192] + z[k + 256];
      z[k] = f;
}}
