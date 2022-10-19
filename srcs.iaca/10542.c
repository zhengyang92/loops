#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int UInt32;
typedef int Int32;

int
fn (Int32 k, UInt32 * fmap, UInt32 * eclass, Int32 i, Int32 H, Int32 j,
    Int32 nblock, UInt32 * bhtab)
{
  for (i = 0; i < nblock; i++)
    {
      if ((bhtab[(i) >> 5] & ((UInt32) 1 << ((i) & 31))))
	j = i;
      k = fmap[i] - H;
      if (k < 0)
	k += nblock;
      eclass[k] = j;
    }
}
