#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef long int ptrdiff_t;

int
fn (int i, uint8_t * list[63], GetBitContext * bitbuf, int m, int n,
    int level, ptrdiff_t pitch)
{
  for (; level > 0; i++)
    {
      if (i == m)
	{
	  m = n;
	  if (--level == 0)
	    break;
	}
      if (!get_bits1 (bitbuf))
	break;
      list[n++] = list[i];
      list[n++] = list[i] + (((level & 1) ? pitch : 1) << ((level >> 1) + 1));
    }
}
