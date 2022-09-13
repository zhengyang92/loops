#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, unsigned int w, unsigned int x, unsigned int depth,
    uint8_t * ptr2)
{
  for (x = 0; x < (w + 7 >> 3) * depth; x++)
    {
      if (depth == 1)
	{
	  ptr[8 * x] = ptr2[x] >> 7;
	  ptr[8 * x + 1] = ptr2[x] >> 6 & 1;
	  ptr[8 * x + 2] = ptr2[x] >> 5 & 1;
	  ptr[8 * x + 3] = ptr2[x] >> 4 & 1;
	  ptr[8 * x + 4] = ptr2[x] >> 3 & 1;
	  ptr[8 * x + 5] = ptr2[x] >> 2 & 1;
	  ptr[8 * x + 6] = ptr2[x] >> 1 & 1;
	  ptr[8 * x + 7] = ptr2[x] & 1;
	}
      else
	{
	  ptr[2 * x] = ptr2[x] >> 4;
	  ptr[2 * x + 1] = ptr2[x] & 0xF;
	}
    }
}
