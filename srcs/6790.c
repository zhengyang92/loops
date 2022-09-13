#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int p, int width, int run, int rows_to_go, uint8_t * dst,
    int stride)
{
  int filled = 0;
  for (i = 0; i < run; i++)
    {
      dst[filled++] = p;
      if (filled >= width)
	{
	  filled = 0;
	  dst -= stride;
	  rows_to_go--;
	  if (rows_to_go <= 0)
	    break;
	}
    }
}
