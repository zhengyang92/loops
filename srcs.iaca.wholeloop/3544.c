#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (uint16_t v[15], ptrdiff_t stride, const uint16_t * top, int j,
    uint16_t * dst)
{
  IACA_START for (j = 0; j < 16; j++)
    {
      memcpy (dst + j * stride, v + j, (16 - 1 - j) * sizeof (uint16_t));
      memset_bpc (dst + j * stride + 16 - 1 - j, top[16 - 1], j + 1);
     } IACA_END
}
