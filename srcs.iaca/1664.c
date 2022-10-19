#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int cf, const uint16_t * counts, int symbol)
{
  for (symbol = 0; counts[symbol + 1] <= cf; symbol++);
}
