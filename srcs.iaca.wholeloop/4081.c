#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (unsigned int i, uint64_t * l, uint64_t t)
{
  IACA_START for (i = 0; l[i] != t; i++); IACA_END
}
