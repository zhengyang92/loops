#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int offset, int step, int code, int j, int pix, uint8_t * out)
{
  int pos = 0;
  for (j = 0; j < 257 - code; j++)
    {
      out[pos] = pix;
      pos += step;
      if (pos >= offset)
	{
	  pos -= offset;
	  pos++;
	}
    }
}
