#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int y, ptrdiff_t stride, int x, int minv, int muv, int maxv,
    const uint8_t * bp)
{
  for (x = 0; x < 4; x++)
    {
      muv += bp[x * 4 + y * stride];
      if (bp[x * 4 + y * stride] < minv)
	minv = bp[x * 4 + y * stride];
      else if (bp[x * 4 + y * stride] > maxv)
	maxv = bp[x * 4 + y * stride];
    }
}
