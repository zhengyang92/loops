#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * inrow, const int w, uint16_t * outrow, int j,
    const uint16_t (*tab)[65536], const int step)
{
  for (j = 0; j < w; j++)
     { IACA_START
      switch (step)
	{
	case 4:
	  outrow[3] = tab[3][inrow[3]];
	case 3:
	  outrow[2] = tab[2][inrow[2]];
	case 2:
	  outrow[1] = tab[1][inrow[1]];
	default:
	  outrow[0] = tab[0][inrow[0]];
	}
      outrow += step;
      inrow += step;
     } IACA_END
}
