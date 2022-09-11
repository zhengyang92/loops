#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int N0, float *X, unsigned int cm, int k,
    const uint8_t celt_bit_deinterleave[16])
{
  int recombine = 0;
  for (k = 0; k < recombine; k++)
    {
      cm = celt_bit_deinterleave[cm];
      celt_haar1 (X, N0 >> k, 1 << k);
    }
}
