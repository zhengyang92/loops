#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (char *value, const uint8_t * ptr8, int i)
{
  IACA_START for (; i < 80 && ptr8[i] != ')'; i++)
    {
      *value++ = ptr8[i];
     } IACA_END
}
