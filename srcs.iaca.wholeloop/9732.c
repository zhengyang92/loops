#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int neg, const int16_t ** tmpU, int i, const int16_t ** chrUSrcPtr)
{
  IACA_START for (i = 0; i < neg; i++)
    {
      tmpU[i] = chrUSrcPtr[neg];
     } IACA_END
}
