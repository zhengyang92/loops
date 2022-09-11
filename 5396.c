#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t vo[7], uint8_t ve[7], ptrdiff_t stride, int j,
    const uint8_t * top, uint8_t * dst)
{
  for (j = 0; j < 8 / 2; j++)
    {
      memcpy (dst + j * 2 * stride, ve + j, (8 - j - 1) * sizeof (uint8_t));
      memset (dst + j * 2 * stride + 8 - j - 1, top[8 - 1], j + 1);
      memcpy (dst + (j * 2 + 1) * stride, vo + j,
	      (8 - j - 1) * sizeof (uint8_t));
      memset (dst + (j * 2 + 1) * stride + 8 - j - 1, top[8 - 1], j + 1);
    }
}
