#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int offset, int code, uint8_t * out, int j, int pix, int step)
{
  int pos = 0;
  for (j = 0; j < 257 - code; j++)
    {
      if (pos < offset)
	out[pos] = pix;
      pos += step;
      if (pos >= offset && step > 1)
	{
	  pos -= offset;
	  pos++;
	}
    }
}
