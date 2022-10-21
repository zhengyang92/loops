#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int fill, const uint8_t celt_bit_interleave[16], float *lowband, int k,
    int N)
{
  int recombine = 0;
  for (k = 0; k < recombine; k++)
     { IACA_START
      if (lowband)
	celt_haar1 (lowband, N >> k, 1 << k);
      fill =
	celt_bit_interleave[fill & 0xF] | celt_bit_interleave[fill >> 4] << 2;
     } IACA_END
}
