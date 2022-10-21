#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned char Bool;
typedef unsigned char UChar;

int
fn (Int32 alphaSize, Int32 k, UChar * len, Int32 i, Int32 j, Int32 maxLen,
    Bool tooLong, Int32 parent[516])
{
  for (i = 1; i <= alphaSize; i++)
     { IACA_START
      j = 0;
      k = i;
      while (parent[k] >= 0)
	{
	  k = parent[k];
	  j++;
	}
      len[i - 1] = j;
      if (j > maxLen)
	tooLong = ((Bool) 1);
     } IACA_END
}
