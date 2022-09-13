#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (int16_t * src2, int offset, int x, int width, const int8_t * filter,
    int shift, uint8_t * dst, uint8_t * src)
{
  for (x = 0; x < width; x++)
    {
      dst[x] =
	av_clip_uint8_c ((((filter[0] * src[x - 1] + filter[1] * src[x] +
			    filter[2] * src[x + 1] + filter[3] * src[x +
								     2 *
								     1]) >> (8
									     -
									     8))
			  + src2[x] + offset) >> shift);
    }
}
