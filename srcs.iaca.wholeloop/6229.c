#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int dc2, int i, int dc0, ptrdiff_t stride, uint16_t * src)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      dc0 += src[-1 + i * stride];
      dc2 += src[-1 + (i + 4) * stride];
     } IACA_END
}
