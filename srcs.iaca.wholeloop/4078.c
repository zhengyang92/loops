#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int i, uint8_t * l, uint8_t t)
{
  IACA_START for (i = 0; l[i] != t; i++);
}
