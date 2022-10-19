#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int num, unsigned int i, uint8_t * bits, unsigned int p)
{
  for (i = p; (i < num) && (bits[i] == 0); ++i);
}
