#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int j, const uint8_t * top, uint8_t * dst,
    uint8_t v[15])
{
  for (j = 0; j < 16; j++)
    {
      memcpy (dst + j * stride, v + j, 16 - 1 - j);
      memset (dst + j * stride + 16 - 1 - j, top[16 - 1], j + 1);
    }
}
