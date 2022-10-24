#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, int dc0, ptrdiff_t stride, int dc1, uint8_t * src)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      dc0 += src[i - stride];
      dc1 += src[4 + i - stride];
     } IACA_END
}
