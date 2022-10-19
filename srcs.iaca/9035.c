#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * p, const uint8_t * end)
{
  for (end -= 3; p < end; p += 4)
    {
      uint32_t x = *(const uint32_t *) p;
      if ((x - 0x01010101) & (~x) & 0x80808080)
	{
	  if (p[1] == 0)
	    {
	      if (p[0] == 0 && p[2] == 1)
		return p;
	      if (p[2] == 0 && p[3] == 1)
		return p + 1;
	    }
	  if (p[3] == 0)
	    {
	      if (p[2] == 0 && p[4] == 1)
		return p + 2;
	      if (p[4] == 0 && p[5] == 1)
		return p + 3;
	    }
	}
    }
}
