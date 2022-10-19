#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * buf, int i, int ff_count, int size)
{
  for (i = size - 1; ff_count; i--)
    {
      int v = buf[i];
      if (v == 0xFF)
	{
	  buf[i + ff_count] = 0;
	  ff_count--;
	}
      buf[i + ff_count] = v;
    }
}
