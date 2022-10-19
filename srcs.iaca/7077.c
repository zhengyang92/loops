#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t v[14], ptrdiff_t stride, const uint8_t * left, int j,
    uint8_t * dst)
{
  for (j = 8 / 2; j < 8; j++)
    {
      memcpy (dst + j * stride, v + j * 2, 8 * 2 - 2 - j * 2);
      memset (dst + j * stride + 8 * 2 - 2 - j * 2, left[8 - 1],
	      2 + j * 2 - 8);
    }
}
