#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double freq, int j, double freqmid[32])
{
  IACA_START for (j = 0; j < 32 && freq >= freqmid[j]; j++);
  IACA_END
}
