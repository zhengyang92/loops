#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x_end, int y_end, const int linesize, const uint8_t * buf,
    int *y_start, int trans)
{
  int is_trans = 1;
  for (int i = *y_start; i < y_end; i++)
    {
      if (buf[linesize * i + x_end] != trans)
	{
	  is_trans = 0;
	  break;
	}
    }
}
