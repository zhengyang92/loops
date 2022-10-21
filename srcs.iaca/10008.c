#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int nb, int n, int k, int centers[4], int min_a)
{
  int range_a = 0;
  for (k = 0, n = 1; k < nb; ++k, n += 2)
     { IACA_START
      ((void) sizeof ((n < 2 * nb) ? 1 : 0), __extension__ (
							     {
							     if (n < 2 * nb);
							     else
							     __assert_fail
							     ("n < 2 * nb",
							      "program.c",
							      169,
							      __extension__
							      __PRETTY_FUNCTION__);}
       ));
      centers[k] = min_a + (n * range_a) / (2 * nb);
     } IACA_END
}
