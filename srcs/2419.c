#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int i, uint8_t * src, unsigned int dc0)
{
  for (i = 0; i < 8; i++)
    {
      ((uint32_t *) (src + i * stride))[0] =
	((uint32_t *) (src + i * stride))[1] = dc0;
    }
}
