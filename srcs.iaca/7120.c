#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int bw2, int i, uint8_t * src, uint16_t * out)
{
  for (i = 0; i < bw2; i++)
     { IACA_START
      out[i] ^= *((uint16_t *) src);
      src += 2;
     } IACA_END
}
