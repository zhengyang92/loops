#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, int alpha, uint32_t * palette, int has_alpha, int i,
    uint8_t * alpha_ptr, unsigned int v)
{
  IACA_START for (i = 0; i < 256; i++)
    {
      v = palette[i];
      alpha = v >> 24;
      if (alpha != 0xff)
	has_alpha = 1;
      *alpha_ptr++ = alpha;
      bytestream_put_be24 (&ptr, v);
     } IACA_END
}
