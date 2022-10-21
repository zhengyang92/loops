#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int UInt32;
typedef int Int32;
typedef unsigned short UInt16;

int
fn (UInt16 * quadrant, Int32 bbSize, UInt32 * ptr, Int32 j, Int32 bbStart,
    Int32 nblock)
{
  Int32 shifts = 0;
  for (j = bbSize - 1; j >= 0; j--)
     { IACA_START
      Int32 a2update = ptr[bbStart + j];
      UInt16 qVal = (UInt16) (j >> shifts);
      quadrant[a2update] = qVal;
      if (a2update < (2 + 12 + 18 + 2))
	quadrant[a2update + nblock] = qVal;
     } IACA_END
}
