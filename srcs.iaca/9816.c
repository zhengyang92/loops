#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;
typedef signed short int16;

int
fn (int16 b, int rc, unsigned char *bp, tmsize_t npixels, tmsize_t i,
    tmsize_t cc, int shft, int16 * tp)
{
  for (i = 0; i < npixels && cc > 0;)
    {
      if (*bp >= 128)
	{
	  if (cc < 2)
	    break;
	  rc = *bp++ + (2 - 128);
	  b = (int16) (*bp++ << shft);
	  cc -= 2;
	  while (rc-- && i < npixels)
	    tp[i++] |= b;
	}
      else
	{
	  rc = *bp++;
	  while (--cc && rc-- && i < npixels)
	    tp[i++] |= (int16) * bp++ << shft;
	}
    }
}
