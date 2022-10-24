#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int z, uint32_t x[128])
{
  IACA_START for (; !x[z - 1]; z--);
  IACA_END
}
