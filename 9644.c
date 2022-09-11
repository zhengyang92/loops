#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int i, uint32_t ncolors, uint8_t blue, uint8_t green, uint8_t red,
    GetByteContext gb, uint32_t * dst)
{
  for (i = 0; i < ncolors; i++)
    {
      bytestream2_skipu (&gb, 4);
      red = bytestream2_get_byteu (&gb);
      bytestream2_skipu (&gb, 1);
      green = bytestream2_get_byteu (&gb);
      bytestream2_skipu (&gb, 1);
      blue = bytestream2_get_byteu (&gb);
      bytestream2_skipu (&gb, 3);
      dst[i] = red << 16 | green << 8 | blue;
    }
}
