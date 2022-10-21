#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int dc0, int dc1, uint8_t * src)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      dc0 += src[i - stride];
      dc1 += src[4 + i - stride];
     } IACA_END
}
