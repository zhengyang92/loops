#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint32_t uint32_t;

int
fn (int planes, uint32_t * palette, GetByteContext gb)
{
  for (int i = 0; i < (1 << planes); i++)
    {
      int v = bytestream2_get_be16 (&gb);
      int r = ((v >> 8) & 0x7) << 5;
      int g = ((v >> 4) & 0x7) << 5;
      int b = ((v) & 0x7) << 5;
      palette[i] = 0xFF000000 | r << 16 | g << 8 | b;
}}
