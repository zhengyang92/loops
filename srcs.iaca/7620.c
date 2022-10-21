#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t * dst, int i, const uint8_t * src)
{
  for (i = 0; i < 120; i += 3)
     { IACA_START
      unsigned sample;
      sample =
	((unsigned) src[i + 0] << 25) | ((unsigned) src[i + 1] << 18) |
	((unsigned) src[i + 2] << 11);
      dst[i / 3] = sample;
} IACA_END }
