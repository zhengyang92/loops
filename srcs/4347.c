#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * c8, float delta, const uint8_t * c5, int x, int width,
    float scale, const uint8_t * c7, const uint8_t * c1, const uint8_t * c3,
    const uint8_t * c2, uint8_t * dst, const uint8_t * c0, const uint8_t * c6)
{
  for (x = 0; x < width; x++)
    {
      float suma =
	c0[x] * -47 + c1[x] * -162 + c2[x] * -47 + c6[x] * 47 + c7[x] * 162 +
	c8[x] * 47;
      float sumb =
	c0[x] * -47 + c2[x] * 47 + c3[x] * -162 + c5[x] * 162 + c6[x] * -47 +
	c8[x] * 47;
      suma /= 256.f;
      sumb /= 256.f;
      dst[x] =
	av_clip_uint8_c (sqrtf (suma * suma + sumb * sumb) * scale + delta);
}}
