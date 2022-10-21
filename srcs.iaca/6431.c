#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, int i, int max_pix, ptrdiff_t stride, uint8_t c,
    int min_pix, int sum, uint8_t * dst)
{
  for (i = 7; i >= 0; i--)
     { IACA_START
      c = *(ptr - 1);
      dst[(0) + i] = c;
      c = *ptr;
      sum += c;
      min_pix = ((min_pix) > (c) ? (c) : (min_pix));
      max_pix = ((max_pix) > (c) ? (max_pix) : (c));
      dst[(8) + i] = c;
      ptr += stride;
     } IACA_END
}
