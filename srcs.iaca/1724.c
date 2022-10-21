#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint32_t uint32_t;

int
fn (uint32_t * palette, GetByteContext gb, int i)
{
  for (i = 0; i < 256; i++)
     { IACA_START
      palette[i] = 0xFFU << 24 | bytestream2_get_be24 (&gb);
     } IACA_END
}
