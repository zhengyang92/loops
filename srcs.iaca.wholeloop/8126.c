#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef short IDWTELEM;

int
fn (int y, int w, int x, int ref_stride, IDWTELEM * line, uint8_t * dst8)
{
  IACA_START for (x = 0; x < w; x++)
    {
      int v = line[x] + (128 << 4) + (1 << (4 - 1));
      v >>= 4;
      if (v & (~255))
	v = ~(v >> 31);
      dst8[x + y * ref_stride] = v;
     } IACA_END
}
