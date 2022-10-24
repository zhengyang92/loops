#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t v[7], ptrdiff_t stride, int j, const uint8_t * top, uint8_t * dst)
{
  IACA_START for (j = 0; j < 8; j++)
    {
      memcpy (dst + j * stride, v + j, (8 - 1 - j) * sizeof (uint8_t));
      memset (dst + j * stride + 8 - 1 - j, top[8 - 1], j + 1);
     } IACA_END
}
