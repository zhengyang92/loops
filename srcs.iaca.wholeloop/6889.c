#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef long int ptrdiff_t;

int
fn (int i, uint8_t * list[63], BitstreamContext * bc, int m, int n, int level,
    ptrdiff_t pitch)
{
  IACA_START for (; level > 0; i++)
    {
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
