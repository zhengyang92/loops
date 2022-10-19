#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (float *X, uint32_t cm, uint32_t N0,
    const uint8_t ff_celt_bit_deinterleave[], int k)
{
  int recombine = 0;
  for (k = 0; k < recombine; k++)
    {
      cm = ff_celt_bit_deinterleave[cm];
      celt_haar1 (X, N0 >> k, 1 << k);
    }
}
