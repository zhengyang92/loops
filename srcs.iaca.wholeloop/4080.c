#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (unsigned int i, uint32_t * l, uint32_t t)
{
  IACA_START for (i = 0; l[i] != t; i++);
  IACA_END
}
