#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int color, int y, int w, int v, int x, unsigned int bitbuf, int h,
    int bitcnt, int x1, int len, const uint8_t * bitmap, int linesize,
    uint8_t * q)
{
  IACA_START for (y = 0; y < h; y++)
    {
      *q++ = 0x11;
      bitbuf = 0;
      bitcnt = 4;
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
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (0xd) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	    }
	  else if (color == 0 && (len >= 3 && len <= 9))
	    {
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (len - 2) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	    }
	  else if (len >= 4 && len <= 7)
	    {
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (8 + len - 4) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (color) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	    }
	  else if (len >= 9 && len <= 24)
	    {
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (0xe) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (len - 9) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (color) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	    }
	  else if (len >= 25)
	    {
	      if (len > 280)
		len = 280;
	      v = len - 25;
	      {
		bitbuf |= (0) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (0xf) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (v >> 4) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (v & 0xf) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      {
		bitbuf |= (color) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	    }
	  else
	    {
	      {
		bitbuf |= (color) << bitcnt;
		bitcnt -= 4;
		if (bitcnt < 0)
		  {
		    bitcnt = 4;
		    *q++ = bitbuf;
		    bitbuf = 0;
		  }
	      };
	      if (color == 0)
		{
		  {
		    bitbuf |= (0xc) << bitcnt;
		    bitcnt -= 4;
		    if (bitcnt < 0)
		      {
			bitcnt = 4;
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
	bitcnt -= 4;
	if (bitcnt < 0)
	  {
	    bitcnt = 4;
	    *q++ = bitbuf;
	    bitbuf = 0;
	  }
      };
      {
	bitbuf |= (0) << bitcnt;
	bitcnt -= 4;
	if (bitcnt < 0)
	  {
	    bitcnt = 4;
	    *q++ = bitbuf;
	    bitbuf = 0;
	  }
      };
      if (bitcnt != 4)
	{
	  *q++ = bitbuf;
	}
      *q++ = 0xf0;
      bitmap += linesize;
     } IACA_END
}
