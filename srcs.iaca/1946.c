#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int w, int linesize, int x, int h, int buf_size,
    uint8_t * line_begin, int x1, int len, const uint8_t * bitmap, int color,
    uint8_t * q)
{
  for (y = 0; y < h; y++)
     { IACA_START
      if (buf_size * 8 < w * 12 + 24)
	return (-(int)
		(('B') | (('U') << 8) | (('F') << 16) |
		 ((unsigned) ('S') << 24)));
      line_begin = q;
      *q++ = 0x12;
      x = 0;
      while (x < w)
	{
	  x1 = x;
	  color = bitmap[x1++];
	  while (x1 < w && bitmap[x1] == color)
	    x1++;
	  len = x1 - x;
	  if (len == 1 && color)
	    {
	      *q++ = color;
	    }
	  else
	    {
	      if (color == 0x00)
		{
		  len = ((len) > (127) ? (127) : (len));
		  *q++ = 0x00;
		  *q++ = len;
		}
	      else if (len > 2)
		{
		  len = ((len) > (127) ? (127) : (len));
		  *q++ = 0x00;
		  *q++ = 0x80 + len;
		  *q++ = color;
		}
	      else if (len == 2)
		{
		  *q++ = color;
		  *q++ = color;
		}
	      else
		{
		  *q++ = color;
		  len = 1;
		}
	    }
	  x += len;
	}
      *q++ = 0x00;
      *q++ = 0xf0;
      bitmap += linesize;
      buf_size -= q - line_begin;
     } IACA_END
}
