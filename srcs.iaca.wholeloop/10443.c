#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint16_t stbi__uint16;

int
fn (unsigned int x, stbi__uint16 * src, stbi__uint16 * dest, int i)
{
  IACA_START for (i = x - 1; i >= 0; --i, src += 3, dest += 4)
    {
      dest[0] = src[0], dest[1] = src[1], dest[2] = src[2], dest[3] = 0xffff;
     } IACA_END
}
