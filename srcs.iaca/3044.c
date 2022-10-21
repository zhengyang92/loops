#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (int32_t * dst_int32_t, int i, const uint8_t * src, int n)
{
  for (i = 0; i < n; i++)
     { IACA_START
      *dst_int32_t++ =
	((uint32_t) src[2] << 28) | (src[1] << 20) | (src[0] << 12) |
	((src[2] & 0x0F) << 8) | src[1];
      *dst_int32_t++ =
	((uint32_t) src[4] << 24) | (src[3] << 16) | ((src[2] & 0xF0) << 8) |
	(src[4] << 4) | (src[3] >> 4);
      src += 5;
     } IACA_END
}
