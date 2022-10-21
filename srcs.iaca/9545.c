#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef long int ptrdiff_t;

int
fn (uint8_t * list[63], unsigned int level, int i, BitstreamContext * bc,
    int m, int n, ptrdiff_t pitch)
{
  for (; level > 0; i++)
     { IACA_START
      if (i == m)
	{
	  m = n;
	  if (--level == 0)
	    break;
	}
      if (bitstream_read_bit (bc) == 0)
	break;
      list[n++] = list[i];
      list[n++] = list[i] + (((level & 1) ? pitch : 1) << (level / 2 + 1));
     } IACA_END
}
