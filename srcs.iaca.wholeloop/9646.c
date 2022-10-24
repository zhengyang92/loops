#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t * out, int i, int bw2, uint8_t * src)
{
  IACA_START for (i = 0; i < bw2; i++)
    {
      out[i] ^= *((uint32_t *) src);
      src += 4;
     } IACA_END
}
