#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned int UInt32;

int
fn (Int32 cc, UInt32 * fmap, UInt32 * eclass, Int32 cc1, Int32 l, Int32 i,
    Int32 r, UInt32 * bhtab)
{
  for (i = l; i <= r; i++)
    {
      cc1 = eclass[fmap[i]];
      if (cc != cc1)
	{
	  bhtab[(i) >> 5] |= ((UInt32) 1 << ((i) & 31));
	  cc = cc1;
	};
    }
}
