#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int w, int linesize, int v, int x, unsigned int bitbuf, int h,
    int bitcnt, int x1, int len, const uint8_t * bitmap, int color,
    uint8_t * q)
{
  for (y = 0; y < h; y++)
     { IACA_START
      *q++ = 0x10;
      bitbuf = 0;
      bitcnt = 6;
      x = 0;
      while (x < w)
	{
	  x1 = x;
	  color = bitmap[x1++];
	  while (x1 < w && bitmap[x1] == color)
	    x1++;
	  len = x1 - x;
	  if (color == 0 && len == 2)
	    {
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (1) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	    }
	  else if (len >= 3 && len <= 10)
	    {
	      v = len - 3;
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= ((v >> 2) | 2) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (v & 3) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (color) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	    }
	  else if (len >= 12 && len <= 27)
	    {
	      v = len - 12;
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (2) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (v >> 2) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (v & 3) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (color) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	    }
	  else if (len >= 29)
	    {
	      if (len > 284)
		len = 284;
	      v = len - 29;
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (3) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= ((v >> 6)) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= ((v >> 4) & 3) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= ((v >> 2) & 3) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (v & 3) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (color) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	    }
	  else
	    {
	      {
		bitbuf |= (color) << bitcnt;
		bitcnt -= 2;
		if (bitcnt < 0)
		  {
		    bitcnt = 6;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      if (color == 0)
		{
		  {
		    bitbuf |= (1) << bitcnt;
		    bitcnt -= 2;
		    if (bitcnt < 0)
		      {
			bitcnt = 6;
			*q++ = bitbuf;
			bitbuf = 0;
		      }
		  };
		}
	      len = 1;
	    }
	  x += len;
	}
      {
	bitbuf |= (0) << bitcnt;
	bitcnt -= 2;
	if (bitcnt < 0)
	  {
	    bitcnt = 6;
	    *q++ = bitbuf;
	    bitbuf = 0;
	  }
      };
      {
	bitbuf |= (0) << bitcnt;
	bitcnt -= 2;
	if (bitcnt < 0)
	  {
	    bitcnt = 6;
	    *q++ = bitbuf;
	    bitbuf = 0;
	  }
      };
      {
	bitbuf |= (0) << bitcnt;
	bitcnt -= 2;
	if (bitcnt < 0)
	  {
	    bitcnt = 6;
	    *q++ = bitbuf;
	    bitbuf = 0;
	  }
      };
      if (bitcnt != 6)
	{
	  *q++ = bitbuf;
	}
      *q++ = 0xf0;
      bitmap += linesize;
     } IACA_END
}
