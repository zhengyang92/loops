#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int s, int y, int dyx, int x, int width, int r, int vy, int vx,
    int shift, uint8_t * dst, int dxx, uint8_t * src, int height, int stride)
{
  for (x = 0; x < 8; x++)
    {
      int index;
      int src_x = vx >> 16;
      int src_y = vy >> 16;
      int frac_x = src_x & (s - 1);
      int frac_y = src_y & (s - 1);
      src_x >>= shift;
      src_y >>= shift;
      if ((unsigned) src_x < width)
	{
	  if ((unsigned) src_y < height)
	    {
	      index = src_x + src_y * stride;
	      dst[y * stride + x] =
		((src[index] * (s - frac_x) + src[index + 1] * frac_x) * (s -
									  frac_y)
		 + (src[index + stride] * (s - frac_x) +
		    src[index + stride + 1] * frac_x) * frac_y +
		 r) >> (shift * 2);
	    }
	  else
	    {
	      index = src_x + av_clip_c (src_y, 0, height) * stride;
	      dst[y * stride + x] =
		((src[index] * (s - frac_x) + src[index + 1] * frac_x) * s +
		 r) >> (shift * 2);
	    }
	}
      else
	{
	  if ((unsigned) src_y < height)
	    {
	      index = av_clip_c (src_x, 0, width) + src_y * stride;
	      dst[y * stride + x] =
		((src[index] * (s - frac_y) +
		  src[index + stride] * frac_y) * s + r) >> (shift * 2);
	    }
	  else
	    {
	      index =
		av_clip_c (src_x, 0, width) + av_clip_c (src_y, 0,
							 height) * stride;
	      dst[y * stride + x] = src[index];
	    }
	}
      vx += dxx;
      vy += dyx;
    }
}
