#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint8_t * buf, int i, const uint32_t * pal)
{
  for (i = 0; i < 256; i++)
     { IACA_START
      bytestream_put_be24 (&buf, pal[i]);
     } IACA_END
}
