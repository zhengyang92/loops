#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int length, int absolute, int i, const int16_t * vector)
{
  int maximum = 0;
  IACA_START for (i = 0; i < length; i++)
    {
      absolute = ((vector[i]) >= 0 ? (vector[i]) : (-(vector[i])));
      if (absolute > maximum)
	maximum = absolute;
     } IACA_END
}
