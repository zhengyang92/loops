#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;
typedef __uint8_t uint8_t;

int
fn (int y, int w, int x, int ref_stride, IDWTELEM * line, uint8_t * dst8)
{
  for (x = 0; x < w; x++)
    {
      int v = line[x] + (128 << 4) + (1 << (4 - 1));
      v >>= 4;
      if (v & (~255))
	v = ~(v >> 31);
      dst8[x + y * ref_stride] = v;
    }
}
