#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int j, const uint16_t * left, uint16_t * dst,
    uint16_t v[30])
{
  for (j = 16 / 2; j < 16; j++)
     { IACA_START
      memcpy (dst + j * stride, v + j * 2,
	      (16 * 2 - 2 - j * 2) * sizeof (uint16_t));
      memset_bpc (dst + j * stride + 16 * 2 - 2 - j * 2, left[16 - 1],
		  2 + j * 2 - 16);
     } IACA_END
}
