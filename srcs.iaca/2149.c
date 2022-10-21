#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * ref, const int linesize, int y_end, const uint8_t * buf,
    int *y_start, const int ref_linesize, int *x_start)
{
  int same_column = 1;
  for (int y = *y_start; y <= y_end; y++)
     { IACA_START
      if (ref[y * ref_linesize + *x_start] != buf[y * linesize + *x_start])
	{
	  same_column = 0;
	  break;
	}
     } IACA_END
}
