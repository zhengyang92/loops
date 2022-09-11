#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int *bounding_values, ptrdiff_t stride, unsigned char *end,
    int filter_value, uint8_t * first_pixel)
{
  for (end = first_pixel + 8 * stride; first_pixel != end;
       first_pixel += stride)
    {
      filter_value =
	(first_pixel[-2] - first_pixel[1]) + (first_pixel[0] -
					      first_pixel[-1]) * 3;
      filter_value = bounding_values[(filter_value + 4) >> 3];
      first_pixel[-1] = av_clip_uint8_c (first_pixel[-1] + filter_value);
      first_pixel[0] = av_clip_uint8_c (first_pixel[0] - filter_value);
    }
}
