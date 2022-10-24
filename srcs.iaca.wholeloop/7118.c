#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t ms, const int tc_divs[3], int i, int *tc)
{
  IACA_START for (i = 0; i < 3; i++)
    {
      tc[i] = ms % tc_divs[i];
      ms /= tc_divs[i];
     } IACA_END
}
