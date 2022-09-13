#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, const uint8_t * msrc, int x, const uint8_t * asrc, uint8_t * dst)
{
  for (x = 0; x < w; x++)
    {
      if (asrc[x] > 0 && asrc[x] < 255)
	dst[x] =
	  ((msrc[x] * 255 / asrc[x]) >
	   (255) ? (255) : (msrc[x] * 255 / asrc[x]));
      else
	dst[x] = msrc[x];
    }
}
