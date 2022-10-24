#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int i, uint8_t * src, unsigned int dc0)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      dc0 += src[-1 + i * stride] + src[i - stride];
      dc0 += src[4 + i - stride];
      dc0 += src[-1 + (i + 4) * stride];
     } IACA_END
}
