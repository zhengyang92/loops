#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned short UInt16;

int
fn (Int32 bc, UInt16 cost[6], Int32 bt, Int32 t, Int32 nGroups)
{
  for (t = 0; t < nGroups; t++)
    if (cost[t] < bc)
      {
	bc = cost[t];
	bt = t;
      }
}
