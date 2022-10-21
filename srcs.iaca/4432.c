#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const float srintensity, const float scale, const float rintensity,
    const float rc, const float gc, const float bc, const int width,
    uint8_t * bptr, uint8_t * gptr, uint8_t * rptr, const float bintensity,
    const float sbintensity, const float sgintensity, const float gintensity)
{
  for (int x = 0; x < width; x++)
     { IACA_START
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
      gptr[x] = av_clip_uint8_c (g * 255.f);
      bptr[x] = av_clip_uint8_c (b * 255.f);
      rptr[x] = av_clip_uint8_c (r * 255.f);
} IACA_END }
