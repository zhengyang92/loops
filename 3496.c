#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;

int
fn (unsigned int *palette32, int i, GetByteContext gb, unsigned char r,
    unsigned char b, unsigned char g)
{
  for (i = 0; i < 256; i++)
    {
      r = bytestream2_get_byteu (&gb) * 4;
      g = bytestream2_get_byteu (&gb) * 4;
      b = bytestream2_get_byteu (&gb) * 4;
      palette32[i] = 0xFFU << 24 | (r << 16) | (g << 8) | (b);
      palette32[i] |= palette32[i] >> 6 & 0x30303;
    }
}
