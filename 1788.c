#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int stride, int y, int b, uint8_t * buf, int x, unsigned int ci,
    int color, int ai, unsigned int ri, uint8_t * data)
{
  for (x = 0; x < 6; x++)
    {
      if (!((data[4 + y] >> (5 - x)) & 0x01))
	color = data[0] & 0x0F;
      else
	color = data[1] & 0x0F;
      ai = ci + x + (stride * (ri + y));
      if (b)
	color ^= buf[ai];
      buf[ai] = color;
    }
}
