#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int linesize, const uint8_t * buf, const int w, int *y_start,
    int trans)
{
  int is_trans = 1;
  for (int i = 0; i < w; i++)
    {
      if (buf[linesize * *y_start + i] != trans)
	{
	  is_trans = 0;
	  break;
	}
    }
}
