#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned int UInt32;
typedef unsigned char UChar;

int
fn (Int32 ftabCopy[256], UInt32 * fmap, Int32 i, Int32 j, UChar * eclass8,
    Int32 nblock)
{
  IACA_START for (i = 0; i < nblock; i++)
    {
      while (ftabCopy[j] == 0)
	j++;
      ftabCopy[j]--;
      eclass8[fmap[i]] = (UChar) j;
     } IACA_END
}
