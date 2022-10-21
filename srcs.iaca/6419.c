#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double freq, int j, double freqmid[32])
{
  for (j = 31; j > 0 && freq <= freqmid[j]; j--) {IACA_START} ; IACA_END
}
