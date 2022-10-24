#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, int i, uint8_t * src)
{
  int dc = 0;
  IACA_START for (i = 0; i < 16; i++)
    {
      dc += src[i - stride];
     } IACA_END
}
