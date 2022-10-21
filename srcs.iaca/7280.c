#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int end, int i, const int16_t ** chrUSrcPtr, const int16_t ** tmpU)
{
  for (; i < end; i++)
     { IACA_START
      tmpU[i] = chrUSrcPtr[i];
     } IACA_END
}
