#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (const unsigned char *src, int yoffset, int i, unsigned char *dst,
    ptrdiff_t dst_stride, int xoffset, int width, int x, ptrdiff_t src_stride,
    int j, int height)
{
  for (i = x; i < x + 4; i++)
    {
      if (i + xoffset >= 0 && i + xoffset < width && j + yoffset >= 0
	  && j + yoffset < height)
	{
	  dst[j * dst_stride + i] =
	    src[(j + yoffset) * src_stride + i + xoffset];
	}
      else
	{
	  dst[j * dst_stride + i] = 0;
	}
    }
}
