#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;
typedef unsigned int uint32;

int
fn (int rc, uint32 * tp, unsigned char *bp, tmsize_t npixels, tmsize_t i,
    tmsize_t cc, int shft, uint32 b)
{
  IACA_START for (i = 0; i < npixels && cc > 0;)
    {
      if (*bp >= 128)
	{
	  if (cc < 2)
	    break;
	  rc = *bp++ + (2 - 128);
	  b = (uint32) * bp++ << shft;
	  cc -= 2;
	  while (rc-- && i < npixels)
	    tp[i++] |= b;
	}
      else
	{
	  rc = *bp++;
	  while (--cc && rc-- && i < npixels)
	    tp[i++] |= (uint32) * bp++ << shft;
	}
     } IACA_END
}
