#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (const uint16_t * left, ptrdiff_t stride, int j, uint16_t * dst,
    uint16_t v[14])
{
  for (j = 8 / 2; j < 8; j++)
    {
      memcpy (dst + j * stride, v + j * 2,
	      (8 * 2 - 2 - j * 2) * sizeof (uint16_t));
      memset_bpc (dst + j * stride + 8 * 2 - 2 - j * 2, left[8 - 1],
		  2 + j * 2 - 8);
    }
}
