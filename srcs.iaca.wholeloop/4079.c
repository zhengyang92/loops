#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int i, uint16_t t, uint16_t * l)
{
  IACA_START for (i = 0; l[i] != t; i++);
  IACA_END
}
