#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutByteContext;
typedef __uint8_t uint8_t;

int
fn (PutByteContext * p, const uint8_t * bits_table, int i)
{
  int n = 0;
  for (i = 1; i <= 16; i++)
    {
      n += bits_table[i];
      bytestream2_put_byte (p, bits_table[i]);
    }
}
