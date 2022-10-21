#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * p2, int length, int32_t * p1, int i)
{
  for (i = 0; i < length; i++)
     { IACA_START
      int32_t a = p1[i];
      int32_t b = p2[i];
      a -= b >> 1;
      p1[i] = a;
      p2[i] = a + b;
     } IACA_END
}
