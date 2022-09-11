#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const float srintensity, const float scale, const float rintensity,
    const float rc, const float gc, const int depth, uint16_t * bptr,
    const int width, uint16_t * rptr, const float bc, const float max,
    const float bintensity, const float sgintensity, uint16_t * gptr,
    const float gintensity, const float sbintensity)
{
  for (int x = 0; x < width; x++)
    {
      float g = gptr[x] * scale;
      float b = bptr[x] * scale;
      float r = rptr[x] * scale;
      float max_color =
	((((r) > (g) ? (r) : (g))) > (b) ? (((r) > (g) ? (r) : (g))) : (b));
      float min_color =
	((((r) > (g) ? (g) : (r))) > (b) ? (b) : (((r) > (g) ? (g) : (r))));
      float color_saturation = max_color - min_color;
      float luma = g * gc + r * rc + b * bc;
      const float cg =
	1.f + gintensity * (1.f - sgintensity * color_saturation);
      const float cb =
	1.f + bintensity * (1.f - sbintensity * color_saturation);
      const float cr =
	1.f + rintensity * (1.f - srintensity * color_saturation);
      g = lerpf (luma, g, cg);
      b = lerpf (luma, b, cb);
      r = lerpf (luma, r, cr);
      gptr[x] = av_clip_uintp2_c (g * max, depth);
      bptr[x] = av_clip_uintp2_c (b * max, depth);
      rptr[x] = av_clip_uintp2_c (r * max, depth);
}}
