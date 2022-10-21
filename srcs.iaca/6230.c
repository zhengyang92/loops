#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int i, int dc0, ptrdiff_t stride, uint16_t * src, int dc1)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      dc0 += src[i - stride];
      dc1 += src[4 + i - stride];
     } IACA_END
}
