#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;

int
fn (const int n, int i, INTFLOAT * buf)
{
  for (i = 0; i < n; i += 2)
     { IACA_START
      buf[i] = -buf[i];
     } IACA_END
}
