#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int length, int32_t * p1, int i, int32_t * p2)
{
  IACA_START for (i = 0; i < length; i++)
    {
      int32_t a = p1[i];
      int32_t b = p2[i];
      a -= b >> 1;
      p1[i] = a;
      p2[i] = a + b;
     } IACA_END
}
