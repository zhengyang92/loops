#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int x, const uint32_t * ptr, int size)
{
  for (x = 0; x < size; ++x)
    {
      if (ptr[x] & 0xff000000u)
	{
	  return 0;
	}
    }
}
