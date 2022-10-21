#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const int n, float *buf)
{
  for (i = 0; i < n; i += 2)
     { IACA_START
      buf[i] = -buf[i];
     } IACA_END
}
