#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, uint8_t * src, int i, unsigned int dc0)
{
  for (i = 0; i < 4; i++)
    {
      ((uint32_t *) (src + i * stride))[0] = dc0;
      ((uint32_t *) (src + i * stride))[1] = dc0;
    }
}
