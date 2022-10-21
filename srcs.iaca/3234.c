#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (int k, INTFLOAT * z)
{
  for (k = 0; k < 64; k++)
     { IACA_START
      INTFLOAT f = z[k] + z[k + 64] + z[k + 128] + z[k + 192] + z[k + 256];
      z[k] = f;
     } IACA_END
}
