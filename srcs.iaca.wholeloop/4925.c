#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int dc0, uint16_t * src, int dc1)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      dc0 += src[i - stride];
      dc1 += src[4 + i - stride];
     } IACA_END
}
