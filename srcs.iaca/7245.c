#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, const int16_t ** tmpV, int end, const int16_t ** chrUSrcPtr,
    const int16_t ** chrVSrcPtr, const int16_t ** tmpU)
{
  for (; i < end; i++)
     { IACA_START
      tmpU[i] = chrUSrcPtr[i];
      tmpV[i] = chrVSrcPtr[i];
     } IACA_END
}
