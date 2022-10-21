#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, uint8_t * src, int i)
{
  int dc = 0;
  for (i = 0; i < 16; i++)
     { IACA_START
      dc += src[-1 + i * stride];
     } IACA_END
}
