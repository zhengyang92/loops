#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t v[7], ptrdiff_t stride, const uint8_t * top, int j, uint8_t * dst)
{
  for (j = 0; j < 8; j++)
     { IACA_START
      memcpy (dst + j * stride, v + j, 8 - 1 - j);
      memset (dst + j * stride + 8 - 1 - j, top[8 - 1], j + 1);
     } IACA_END
}
