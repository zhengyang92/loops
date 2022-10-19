#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t ve[7], uint8_t vo[7], ptrdiff_t stride, const uint8_t * top,
    int j, uint8_t * dst)
{
  for (j = 0; j < 8 / 2; j++)
    {
      memcpy (dst + j * 2 * stride, ve + j, 8 - (j + 1));
      memset (dst + j * 2 * stride + 8 - j - 1, top[8 - 1], j + 1);
      memcpy (dst + (j * 2 + 1) * stride, vo + j, 8 - (j + 1));
      memset (dst + (j * 2 + 1) * stride + 8 - j - 1, top[8 - 1], j + 1);
    }
}
