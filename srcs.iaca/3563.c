#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (uint16_t vo[31], ptrdiff_t stride, uint16_t ve[31], const uint16_t * top,
    int j, uint16_t * dst)
{
  for (j = 0; j < 32 / 2; j++)
    {
      memcpy (dst + j * 2 * stride, ve + j, (32 - j - 1) * sizeof (uint16_t));
      memset_bpc (dst + j * 2 * stride + 32 - j - 1, top[32 - 1], j + 1);
      memcpy (dst + (j * 2 + 1) * stride, vo + j,
	      (32 - j - 1) * sizeof (uint16_t));
      memset_bpc (dst + (j * 2 + 1) * stride + 32 - j - 1, top[32 - 1],
		  j + 1);
    }
}
