#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x_end, const uint8_t * ref, const int linesize, int y_end,
    const uint8_t * buf, int *y_start, const int ref_linesize)
{
  int same_column = 1;
  for (int y = *y_start; y <= y_end; y++)
    {
      if (ref[y * ref_linesize + x_end] != buf[y * linesize + x_end])
	{
	  same_column = 0;
	  break;
	}
    }
}
