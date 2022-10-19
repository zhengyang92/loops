#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned char *dest, unsigned char *src, unsigned int x, int i)
{
  for (i = x - 1; i >= 0; --i, src += 2, dest += 4)
    {
      dest[0] = dest[1] = dest[2] = src[0], dest[3] = src[1];
    }
}
