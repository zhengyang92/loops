#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutByteContext;
typedef __int32_t int32_t;

int
fn (const int32_t * src32, PutByteContext pb)
{
  IACA_START for (int i = 2; i; i--)
    {
      bytestream2_put_be16 (&pb, src32[0] >> 16);
      bytestream2_put_be16 (&pb, src32[1] >> 16);
      bytestream2_put_byte (&pb, (*src32++) >> 24);
      bytestream2_put_byte (&pb, (*src32++) >> 24);
}IACA_END}
