#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int x, const uint8_t ** coordinates, int coord, int max, int limit)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      if (coord & (1 << i))
	{
	  max =
	    ((max) >
	     (*(coordinates[i] + x)) ? (max) : (*(coordinates[i] + x)));
	}
      max = ((max) > (limit) ? (limit) : (max));
     } IACA_END
}
