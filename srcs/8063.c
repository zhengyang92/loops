#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (GetByteContext gb, int32_t * dst32, uint8_t t, int i)
{
  for (i = 2; i; i--)
    {
      dst32[0] = bytestream2_get_be16u (&gb) << 16;
      dst32[1] = bytestream2_get_be16u (&gb) << 16;
      t = bytestream2_get_byteu (&gb);
      *dst32++ += (t & 0xf0) << 8;
      *dst32++ += (t & 0x0f) << 12;
    }
}
