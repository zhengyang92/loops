#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int v, uint32_t * palette, uint8_t ** bytestream, int i)
{
  IACA_START for (i = 0; i < 256; i++)
    {
      v = palette[i];
      bytestream_put_be24 (bytestream, v);
     } IACA_END
}