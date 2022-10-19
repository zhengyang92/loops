#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, const uint16_t * top, uint16_t v[31], int j,
    uint16_t * dst)
{
  for (j = 0; j < 32; j++)
    {
      memcpy (dst + j * stride, v + j, (32 - 1 - j) * sizeof (uint16_t));
      memset_bpc (dst + j * stride + 32 - 1 - j, top[32 - 1], j + 1);
    }
}
