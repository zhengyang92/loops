#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * buf, const int HEAD, int i, int L)
{
  IACA_START for (i = 0; i < HEAD; i++)
    {
      L += buf[i];
      buf[i] = L;
     } IACA_END
}
