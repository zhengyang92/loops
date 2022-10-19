#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int j, const uint8_t * top, uint8_t * dst,
    uint8_t ve[15], uint8_t vo[15])
{
  for (j = 0; j < 16 / 2; j++)
    {
      memcpy (dst + j * 2 * stride, ve + j, (16 - j - 1) * sizeof (uint8_t));
      memset (dst + j * 2 * stride + 16 - j - 1, top[16 - 1], j + 1);
      memcpy (dst + (j * 2 + 1) * stride, vo + j,
	      (16 - j - 1) * sizeof (uint8_t));
      memset (dst + (j * 2 + 1) * stride + 16 - j - 1, top[16 - 1], j + 1);
    }
}
