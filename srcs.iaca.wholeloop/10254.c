#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned char *dest, unsigned char *src, unsigned int x, int i)
{
  IACA_START for (i = x - 1; i >= 0; --i, src += 1, dest += 2)
    {
      dest[0] = src[0], dest[1] = 255;
     } IACA_END
}
