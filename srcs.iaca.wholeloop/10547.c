#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned short UInt16;
typedef unsigned char UChar;

int
fn (UChar * block, UInt16 * quadrant, Int32 i, Int32 nblock)
{
  IACA_START for (i = 0; i < (2 + 12 + 18 + 2); i++)
    {
      block[nblock + i] = block[i];
      quadrant[nblock + i] = 0;
     } IACA_END
}
