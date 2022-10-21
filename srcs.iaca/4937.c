#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, uint8_t * src, int i, unsigned int dc0)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      dc0 += src[-1 + i * stride] + src[i - stride];
      dc0 += src[4 + i - stride];
      dc0 += src[-1 + (i + 4) * stride];
     } IACA_END
}
