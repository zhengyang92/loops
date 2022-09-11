#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, int radius, int h, const uint16_t * filter, int k,
    const uint8_t * src, int filt_w, ptrdiff_t src_stride, int j)
{
  int sum = 0;
  for (k = 0; k < filt_w; k++)
    {
      int i_tap =
	((i - radius + k) >= 0 ? (i - radius + k) : (-(i - radius + k)));
      if (i_tap >= h)
	{
	  i_tap = h - (i_tap - h + 1);
	}
      sum += filter[k] * src[i_tap * src_stride + j];
    }
}
