#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int i, int x, int pos, int j, uint8_t * src, int stride)
{
  int lowest = 255;
  int highest = 0;
  for (j = 0; j <= 15; j++)
    {
      pos = (y + i) * stride + (x + j);
      if (src[pos] < lowest)
	lowest = src[pos];
      else if (src[pos] > highest)
	{
	  highest = src[pos];
	}
    }
}
