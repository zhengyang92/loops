#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, const int16_t ** tmpV, int neg, const int16_t ** chrUSrcPtr,
    const int16_t ** chrVSrcPtr, const int16_t ** tmpU)
{
  for (i = 0; i < neg; i++)
     { IACA_START
      tmpU[i] = chrUSrcPtr[neg];
      tmpV[i] = chrVSrcPtr[neg];
     } IACA_END
}
