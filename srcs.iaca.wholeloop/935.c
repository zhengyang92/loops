#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int x, const uint8_t ** coordinates, int min, int coord, int limit)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      if (coord & (1 << i))
	{
	  min =
	    ((min) >
	     (*(coordinates[i] + x)) ? (*(coordinates[i] + x)) : (min));
	}
      min = ((min) > (limit) ? (min) : (limit));
     } IACA_END
}
