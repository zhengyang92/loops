#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int end, int i, const int16_t ** chrUSrcPtr, const int16_t ** tmpU)
{
  IACA_START for (; i < end; i++)
    {
      tmpU[i] = chrUSrcPtr[i];
     } IACA_END
}
