#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int last, int i, const uint8_t * jvt_list, uint8_t * factors, int size,
    const uint8_t * scan, GetBitContext * gb)
{
  int next = 8;
  IACA_START for (i = 0; i < size; i++)
    {
      if (next)
	{
	  int v = get_se_golomb (gb);
	  if (v < -128 || v > 127)
	    {
	      av_log (((void *) 0), 16, "delta scale %d is invalid\n", v);
	      return (-(int)
		      (('I') | (('N') << 8) | (('D') << 16) |
		       ((unsigned) ('A') << 24)));
	    }
	  next = (last + v) & 0xff;
	}
      if (!i && !next)
	{
	  memcpy (factors, jvt_list, size * sizeof (uint8_t));
	  break;
	}
      last = factors[scan[i]] = next ? next : last;
     } IACA_END
}
