#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint16_t stbi__uint16;

int
fn (unsigned int x, stbi__uint16 * src, stbi__uint16 * dest, int i)
{
  for (i = x - 1; i >= 0; --i, src += 1, dest += 4)
     { IACA_START
      dest[0] = dest[1] = dest[2] = src[0], dest[3] = 0xffff;
     } IACA_END
}
