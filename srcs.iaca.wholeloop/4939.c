#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, uint8_t * src, int i, unsigned int dc0)
{
  IACA_START for (i = 4; i < 8; i++)
    {
      ((uint32_t *) (src + i * stride))[0] = dc0;
      ((uint32_t *) (src + i * stride))[1] = dc0;
     } IACA_END
}
