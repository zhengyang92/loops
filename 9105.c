#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int y, uint8_t * cols, int x, int width, uint32_t col, uint8_t * grps,
    int bpp, uint8_t * out, int stride)
{
  for (x = 0; x < width; x++)
    {
      if (grps)
	cols[1] = grps[(x >> 1) + 1];
      out[x + y * stride] = cols[col & ((1 << bpp) - 1)];
      col >>= bpp;
    }
}
