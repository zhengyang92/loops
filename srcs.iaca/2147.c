#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int linesize, int y_end, const uint8_t * buf, int *y_start,
    int trans, int *x_start)
{
  int is_trans = 1;
  for (int i = *y_start; i < y_end; i++)
     { IACA_START
      if (buf[linesize * i + *x_start] != trans)
	{
	  is_trans = 0;
	  break;
	}
     } IACA_END
}
