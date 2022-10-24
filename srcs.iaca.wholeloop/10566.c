#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int UInt32;
typedef int Int32;

int
fn (Int32 cc, UInt32 * fmap, Int32 cc1, UInt32 * eclass, Int32 l, Int32 i,
    Int32 r, UInt32 * bhtab)
{
  IACA_START for (i = l; i <= r; i++)
    {
      cc1 = eclass[fmap[i]];
      if (cc != cc1)
	{
	  bhtab[(i) >> 5] |= ((UInt32) 1 << ((i) & 31));
	  cc = cc1;
	};
     } IACA_END
}
