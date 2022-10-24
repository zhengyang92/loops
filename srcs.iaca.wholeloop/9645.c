#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int bw2, uint8_t * src, int i, uint16_t * out)
{
  IACA_START for (i = 0; i < bw2; i++)
    {
      out[i] ^= *((uint16_t *) src);
      src += 2;
     } IACA_END
}
