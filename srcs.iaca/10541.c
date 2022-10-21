#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int UInt32;
typedef int Int32;

int
fn (Int32 i, Int32 nblock, UInt32 * bhtab)
{
  for (i = 0; i < 32; i++)
     { IACA_START
      bhtab[(nblock + 2 * i) >> 5] |= ((UInt32) 1 << ((nblock + 2 * i) & 31));
      bhtab[(nblock + 2 * i + 1) >> 5] &=
	~((UInt32) 1 << ((nblock + 2 * i + 1) & 31));
     } IACA_END
}
