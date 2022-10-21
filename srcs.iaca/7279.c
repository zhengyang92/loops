#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int neg, const int16_t ** tmpU, const int16_t ** chrUSrcPtr, int i)
{
  for (i = 0; i < neg; i++)
     { IACA_START
      tmpU[i] = chrUSrcPtr[neg];
     } IACA_END
}
