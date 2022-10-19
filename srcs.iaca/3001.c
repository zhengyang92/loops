#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int fill, float *X, float *lowband,
    const uint8_t ff_celt_bit_interleave[], int quant, int k, int N)
{
  int recombine = 0;
  for (k = 0; k < recombine; k++)
    {
      if (quant || lowband)
	celt_haar1 (quant ? X : lowband, N >> k, 1 << k);
      fill =
	ff_celt_bit_interleave[fill & 0xF] | ff_celt_bit_interleave[fill >> 4]
	<< 2;
    }
}
