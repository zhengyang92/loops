#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * cdf, unsigned int symbol, unsigned int k)
{
  IACA_START for (k = 0; cdf[k] <= symbol; k++); IACA_END
}
