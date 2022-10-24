#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int shift, int16_t weight[10], int i)
{
  IACA_START for (i = 0; i < 10; i++)
    {
      weight[i] <<= shift;
     } IACA_END
}
