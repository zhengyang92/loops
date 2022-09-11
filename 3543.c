#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, uint16_t v[7], const uint16_t * top, int j,
    uint16_t * dst)
{
  for (j = 0; j < 8; j++)
    {
      memcpy (dst + j * stride, v + j, (8 - 1 - j) * sizeof (uint16_t));
      memset_bpc (dst + j * stride + 8 - 1 - j, top[8 - 1], j + 1);
    }
}
