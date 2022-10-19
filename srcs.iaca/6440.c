#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * __restrict end, const uint8_t * __restrict p)
{
  for (; p < end; p += 2)
    {
      if (!*p)
	{
	  if (!p[-1] && p[1])
	    return p - 1;
	  else if (!p[1] && p[2])
	    return p;
	}
    }
}
