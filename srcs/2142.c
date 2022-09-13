#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint32_t uint32_t;

int
fn (int planes, uint32_t * palette, GetByteContext gb)
{
  for (int i = 0; i < (1 << planes); i++)
    {
      int r = (bytestream2_get_be16 (&gb) * 51 + 100) / 200;
      int g = (bytestream2_get_be16 (&gb) * 51 + 100) / 200;
      int b = (bytestream2_get_be16 (&gb) * 51 + 100) / 200;
      palette[i] = 0xFF000000 | r << 16 | g << 8 | b;
}}
