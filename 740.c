#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float delta, int x, int width, float scale, const uint8_t ** c,
    uint8_t * dst)
{
  for (x = 0; x < width; x++)
    {
      float suma = c[0][x] * 1 + c[1][x] * -1;
      float sumb = c[4][x] * 1 + c[3][x] * -1;
      dst[x] =
	av_clip_uint8_c (sqrtf (suma * suma + sumb * sumb) * scale + delta);
}}
