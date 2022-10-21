#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (const uint16_t * left, ptrdiff_t stride, int j, uint16_t v[62],
    uint16_t * dst)
{
  for (j = 32 / 2; j < 32; j++)
     { IACA_START
      memcpy (dst + j * stride, v + j * 2,
	      (32 * 2 - 2 - j * 2) * sizeof (uint16_t));
      memset_bpc (dst + j * stride + 32 * 2 - 2 - j * 2, left[32 - 1],
		  2 + j * 2 - 32);
     } IACA_END
}
