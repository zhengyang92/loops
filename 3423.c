#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint32_t uint32_t;

int
fn (unsigned int y, unsigned int v, GetByteContext gb, uint32_t * pal)
{
  for (y = 0; y < 256; y++)
    {
      v = bytestream2_get_be32 (&gb);
      pal[y] = (v >> 8) + (v << 24);
    }
}
