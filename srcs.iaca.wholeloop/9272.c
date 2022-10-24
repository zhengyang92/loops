#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int dc2, int dc3, int i, ptrdiff_t stride, int dc4, int dc0, int dc1,
    uint8_t * src)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      dc0 += src[-1 + i * stride] + src[i - stride];
      dc1 += src[4 + i - stride];
      dc2 += src[-1 + (i + 4) * stride];
      dc3 += src[-1 + (i + 8) * stride];
      dc4 += src[-1 + (i + 12) * stride];
     } IACA_END
}
