#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, const uint8_t * left, uint8_t v[30], int j,
    uint8_t * dst)
{
  for (j = 16 / 2; j < 16; j++)
     { IACA_START
      memcpy (dst + j * stride, v + j * 2, 16 * 2 - 2 - j * 2);
      memset (dst + j * stride + 16 * 2 - 2 - j * 2, left[16 - 1],
	      2 + j * 2 - 16);
     } IACA_END
}
