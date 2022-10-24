#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const int n, float *buf)
{
  IACA_START for (i = 0; i < n; i += 2)
    {
      buf[i] = -buf[i];
     } IACA_END
}
