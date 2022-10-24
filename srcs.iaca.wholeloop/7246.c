#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t ** tmpU, const int16_t ** tmpV, int i,
    const int vChrFilterSize)
{
  IACA_START for (; i < vChrFilterSize; i++)
    {
      tmpU[i] = tmpU[i - 1];
      tmpV[i] = tmpV[i - 1];
     } IACA_END
}
