#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (ptrdiff_t stride, int i, uint16_t * src)
{
  int dc = 0;
  for (i = 0; i < 16; i++)
     { IACA_START
      dc += src[-1 + i * stride];
     } IACA_END
}
