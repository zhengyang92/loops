#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, const uint8_t * left, uint8_t v[62], int j,
    uint8_t * dst)
{
  IACA_START for (j = 32 / 2; j < 32; j++)
    {
      memcpy (dst + j * stride, v + j * 2,
	      (32 * 2 - 2 - j * 2) * sizeof (uint8_t));
      memset (dst + j * stride + 32 * 2 - 2 - j * 2, left[32 - 1],
	      2 + j * 2 - 32);
     } IACA_END
}
