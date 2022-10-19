#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * p, uint8_t * end)
{
  for (; p < end - 3; p += 4)
    {
      uint32_t x = *(uint32_t *) p;
      if (x & (~(x + 0x01010101)) & 0x80808080)
	{
	  if (p[0] == 0xff)
	    {
	      return p;
	    }
	  else if (p[1] == 0xff)
	    {
	      return p + 1;
	    }
	  else if (p[2] == 0xff)
	    {
	      return p + 2;
	    }
	  else if (p[3] == 0xff)
	    {
	      return p + 3;
	    }
	}
    }
}
