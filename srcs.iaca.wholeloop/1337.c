#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutByteContext;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * value_table, PutByteContext * p, int i)
{
  int n = 0;
  IACA_START for (i = 0; i < n; i++)
    {
      bytestream2_put_byte (p, value_table[i]);
     } IACA_END
}
