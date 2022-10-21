#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int linesize, int y_end, const uint8_t * buf, const int w,
    int trans)
{
  int is_trans = 1;
  for (int i = 0; i < w; i++)
     { IACA_START
      if (buf[linesize * y_end + i] != trans)
	{
	  is_trans = 0;
	  break;
	}
     } IACA_END
}
