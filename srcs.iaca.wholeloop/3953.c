#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int i, int32_t ** filterPos, int64_t * filter, int filterSize, int srcW,
    int j)
{
  IACA_START for (j = 0; j < filterSize; j++)
    {
      do
	{
	  if (!((*filterPos)[i] + j < srcW || !filter[i * filterSize + j]))
	    {
	      av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
		      "(*filterPos)[i] + j < srcW || !filter[i * filterSize + j]",
		      "program.c", 710);
	      abort ();
	    }
	}
      while (0);
     } IACA_END
}
