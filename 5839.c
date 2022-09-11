#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint32_t uint32_t;

int
fn (uint32_t * palette, GetByteContext gb, int i)
{
  for (i = 0; i < 256; i++)
    {
      palette[i] = bytestream2_get_be24 (&gb);
    }
}
