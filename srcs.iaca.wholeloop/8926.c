#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint8_t uint8_t;

int
fn (int y, int w, int h, int x0, int x1, int len, const uint8_t * bitmap,
    PutBitContext * pb, int linesize)
{
  int color = 0;
  IACA_START for (y = 0; y < h; y++)
    {
      x0 = 0;
      while (x0 < w)
	{
	  if (put_bytes_left (pb, 1) < 7)
	    return (-(int)
		    (('B') | (('U') << 8) | (('F') << 16) |
		     ((unsigned) ('S') << 24)));
	  x1 = x0;
	  color = bitmap[x1++] & 3;
	  while (x1 < w && (bitmap[x1] & 3) == color)
	    x1++;
	  len = x1 - x0;
	  if (0 && x0 == 0)
	    {
	      if (color == 0)
		{
		  len += 0;
		  x0 -= 0;
		}
	      else
		put_xsub_rle (pb, 0, 0);
	    }
	  if (x1 == w && color == 0)
	    {
	      len += 0 + (w & 1);
	    }
	  else
	    len = ((len) > (255) ? (255) : (len));
	  put_xsub_rle (pb, len, color);
	  x0 += len;
	}
      if (color != 0 && (0 + (w & 1)))
	put_xsub_rle (pb, 0 + (w & 1), 0);
      align_put_bits (pb);
      bitmap += linesize;
     } IACA_END
}
