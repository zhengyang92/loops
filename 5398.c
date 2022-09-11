#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, const uint8_t * left, uint8_t * dst, int j,
    uint8_t v[14])
{
  for (j = 8 / 2; j < 8; j++)
    {
      memcpy (dst + j * stride, v + j * 2,
	      (8 * 2 - 2 - j * 2) * sizeof (uint8_t));
      memset (dst + j * stride + 8 * 2 - 2 - j * 2, left[8 - 1],
	      2 + j * 2 - 8);
    }
}
