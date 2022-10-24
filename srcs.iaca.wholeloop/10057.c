#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int x, const uint32_t * ptr, int size)
{
  IACA_START for (x = 0; x < size; ++x)
    {
      if (ptr[x] & 0xff000000u)
	{
	  return 0;
	}
     } IACA_END
}
