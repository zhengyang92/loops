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
  for (i = 0; i < size; i++)
     { IACA_START
      if (next)
	next = (last + get_se_golomb (gb)) & 0xff;
      if (!i && !next)
	{
	  memcpy (factors, jvt_list, size * sizeof (uint8_t));
	  break;
	}
      last = factors[scan[i]] = next ? next : last;
     } IACA_END
}
