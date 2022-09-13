#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int pixel, uint32_t idx, uint8_t quad[4])
{
  for (int w = 0; w < 4; w++)
    {
      if (quad[w] == pixel)
	{
	  idx = w;
	  break;
	}
    }
}
