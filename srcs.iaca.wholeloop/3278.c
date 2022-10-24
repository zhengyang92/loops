#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;
typedef __uint8_t uint8_t;

int
fn (int y, int w, int x, int ref_stride, uint8_t * dst8, IDWTELEM * buf)
{
  IACA_START for (x = 0; x < w; x++)
    {
      int v = buf[x + y * w] + (128 << 4) + (1 << (4 - 1));
      v >>= 4;
      if (v & (~255))
	v = ~(v >> 31);
      dst8[x + y * ref_stride] = v;
     } IACA_END
}
