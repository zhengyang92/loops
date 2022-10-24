#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int j, const uint16_t * left, uint16_t * dst,
    uint16_t v[14])
{
  IACA_START for (j = 8 / 2; j < 8; j++)
    {
      memcpy (dst + j * stride, v + j * 2,
	      (8 * 2 - 2 - j * 2) * sizeof (uint16_t));
      memset_bpc (dst + j * stride + 8 * 2 - 2 - j * 2, left[8 - 1],
		  2 + j * 2 - 8);
     } IACA_END
}
