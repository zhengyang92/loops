#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned short UInt16;
typedef int Int32;

int
fn (Int32 bc, UInt16 cost[6], Int32 bt, Int32 t, Int32 nGroups)
{
  for (t = 0; t < nGroups; t++) {
		IACA_START
    if (cost[t] < bc)
      {
	bc = cost[t];
	bt = t;
      }
  } IACA_END
}
