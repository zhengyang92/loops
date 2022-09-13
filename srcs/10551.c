#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned int UInt32;

int
fn (Int32 runningOrder[256], UInt32 * ftab, Int32 i, Int32 j, Int32 vv)
{
  Int32 h = 1;
  for (i = h; i <= 255; i++)
    {
      vv = runningOrder[i];
      j = i;
      while ((ftab[((runningOrder[j - h]) + 1) << 8] -
	      ftab[(runningOrder[j - h]) << 8]) >
	     (ftab[((vv) + 1) << 8] - ftab[(vv) << 8]))
	{
	  runningOrder[j] = runningOrder[j - h];
	  j = j - h;
	  if (j <= (h - 1))
	    goto zero;
	}
    zero:runningOrder[j] = vv;
    }
}
