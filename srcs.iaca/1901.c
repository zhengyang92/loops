#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * s1, const uint8_t * w, const uint8_t * s2,
    const uint8_t * s3, int x, uint8_t * dst, const uint8_t * s0)
{
  for (x = 0; x < 16; x++)
     { IACA_START
      (dst[x]) =
	((s0[x] * w[0] + s1[x] * w[1] + s2[x] * w[2] + s3[x] * w[3] +
	  8) >> 4);
     } IACA_END
}
