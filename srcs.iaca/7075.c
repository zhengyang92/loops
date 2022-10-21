#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, const uint8_t * top, uint8_t ve[31], int j,
    uint8_t * dst, uint8_t vo[31])
{
  for (j = 0; j < 32 / 2; j++)
     { IACA_START
      memcpy (dst + j * 2 * stride, ve + j, 32 - (j + 1));
      memset (dst + j * 2 * stride + 32 - j - 1, top[32 - 1], j + 1);
      memcpy (dst + (j * 2 + 1) * stride, vo + j, 32 - (j + 1));
      memset (dst + (j * 2 + 1) * stride + 32 - j - 1, top[32 - 1], j + 1);
     } IACA_END
}
