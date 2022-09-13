#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int j, uint8_t v[31], const uint8_t * top,
    uint8_t * dst)
{
  for (j = 0; j < 32; j++)
    {
      memcpy (dst + j * stride, v + j, (32 - 1 - j) * sizeof (uint8_t));
      memset (dst + j * stride + 32 - 1 - j, top[32 - 1], j + 1);
    }
}
