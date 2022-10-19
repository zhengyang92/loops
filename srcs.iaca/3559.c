#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (uint16_t ve[7], ptrdiff_t stride, const uint16_t * top, int j,
    uint16_t * dst, uint16_t vo[7])
{
  for (j = 0; j < 8 / 2; j++)
    {
      memcpy (dst + j * 2 * stride, ve + j, (8 - j - 1) * sizeof (uint16_t));
      memset_bpc (dst + j * 2 * stride + 8 - j - 1, top[8 - 1], j + 1);
      memcpy (dst + (j * 2 + 1) * stride, vo + j,
	      (8 - j - 1) * sizeof (uint16_t));
      memset_bpc (dst + (j * 2 + 1) * stride + 8 - j - 1, top[8 - 1], j + 1);
    }
}
