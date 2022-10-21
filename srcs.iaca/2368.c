#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int dc2, int i, int dc0, ptrdiff_t stride, uint16_t * src, int dc1)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      dc0 += src[-1 + i * stride] + src[i - stride];
      dc1 += src[4 + i - stride];
      dc2 += src[-1 + (i + 4) * stride];
     } IACA_END
}
