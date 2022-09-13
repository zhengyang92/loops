#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __int32_t int32_t;

int
fn (GetByteContext gb, int32_t * dst32, int i)
{
  for (i = 2; i; i--)
    {
      dst32[0] = bytestream2_get_be16u (&gb) << 16;
      dst32[1] = bytestream2_get_be16u (&gb) << 16;
      *dst32++ += bytestream2_get_byteu (&gb) << 8;
      *dst32++ += bytestream2_get_byteu (&gb) << 8;
    }
}
