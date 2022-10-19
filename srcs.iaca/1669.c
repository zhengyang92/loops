#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;

int
fn (int bits, int dy, const int w, uint8_t * dst, int pos, const int h,
    const int l, GetByteContext * gb)
{
  for (int i = 0; i < 4; i++)
    {
      switch (bits & 3)
	{
	case 0:
	  break;
	case 1:
	  if (dy < 1 && !pos)
	    return (-(int)
		    (('I') | (('N') << 8) | (('D') << 16) |
		     ((unsigned) ('A') << 24)));
	  else
	    dst[pos] = pos ? dst[pos - 1] : dst[-l + w - 1];
	  break;
	case 2:
	  if (dy < 1)
	    return (-(int)
		    (('I') | (('N') << 8) | (('D') << 16) |
		     ((unsigned) ('A') << 24)));
	  dst[pos] = dst[pos - l];
	  break;
	case 3:
	  dst[pos] = bytestream2_get_byte (gb);
	  break;
	}
      pos++;
      if (pos >= w)
	{
	  pos -= w;
	  dst += l;
	  dy++;
	  if (dy >= h)
	    return 0;
	}
      bits >>= 2;
    }
}
