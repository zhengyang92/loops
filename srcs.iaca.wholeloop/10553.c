#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned char UChar;
typedef unsigned char Bool;
typedef unsigned int UInt32;

int
fn (Bool bigDone[256], UChar c1, Int32 k, UInt32 * ftab, Int32 copyStart[256],
    UInt32 * ptr, Int32 j, UChar * block, Int32 nblock, Int32 ss)
{
  IACA_START for (j = ftab[ss << 8] & (~((1 << 21))); j < copyStart[ss]; j++)
    {
      k = ptr[j] - 1;
      if (k < 0)
	k += nblock;
      c1 = block[k];
      if (!bigDone[c1])
	ptr[copyStart[c1]++] = k;
     } IACA_END
}
