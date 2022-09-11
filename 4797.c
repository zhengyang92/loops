#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef long unsigned int size_t;

int
fn (uint32_t * dst, const uint32_t * src, size_t i, size_t colors_seen)
{
  int seen = 0;
  for (size_t c = 0; c < colors_seen; c++)
    {
      if (src[i] == dst[c])
	{
	  seen = 1;
	  break;
	}
    }
}
