#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const uint8_t * src, int pos, uint8_t * dst, int height,
    int stride)
{
  for (i = 0; i < 4; i++)
    {
      if ((pos + i) < 0 || (pos + i) >= height * stride)
	dst[i] = 0;
      else
	dst[i] = src[i];
    }
}
