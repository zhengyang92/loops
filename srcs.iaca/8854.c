#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src3, const uint8_t * src4, int dy, const uint8_t * src2,
    int x, int b_w, int dx, uint8_t * dst, const uint8_t * src1)
{
  for (x = 0; x < b_w; x++)
     { IACA_START
      dst[x] =
	((8 - dx) * (8 - dy) * src1[x] + dx * (8 - dy) * src2[x] +
	 (8 - dx) * dy * src3[x] + dx * dy * src4[x] + 32) >> 6;
     } IACA_END
}
