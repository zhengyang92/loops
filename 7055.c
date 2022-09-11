#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t v[7], ptrdiff_t stride, const uint8_t * top, int j, uint8_t * dst)
{
  for (j = 0; j < 8; j++)
    {
      memcpy (dst + j * stride, v + j, 8 - 1 - j);
      memset (dst + j * stride + 8 - 1 - j, top[8 - 1], j + 1);
    }
}
