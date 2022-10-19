#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int y, int b_h, ptrdiff_t stride, const unsigned int color4,
    uint8_t * dst)
{
  for (y = 0; y < b_h; y++)
    {
      *(uint32_t *) & dst[0 + y * stride] = color4;
      *(uint32_t *) & dst[4 + y * stride] = color4;
    }
}
