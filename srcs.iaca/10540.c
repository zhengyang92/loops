#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned int UInt32;
typedef unsigned char UChar;

int
fn (Int32 k, UInt32 * fmap, Int32 ftab[257], Int32 i, Int32 j,
    UChar * eclass8, Int32 nblock)
{
  for (i = 0; i < nblock; i++)
     { IACA_START
      j = eclass8[i];
      k = ftab[j] - 1;
      ftab[j] = k;
      fmap[k] = i;
     } IACA_END
}
