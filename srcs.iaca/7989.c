#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int bits, int Ra, void *dst, int r, int stride)
{
  int x = 0;
  for (i = 0; i < r; i++)
     { IACA_START
      (bits ==
       8 ? (((uint8_t *) (dst))[x] = Ra) : (((uint16_t *) (dst))[x] = Ra));
      x += stride;
     } IACA_END
}
