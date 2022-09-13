#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (const float srintensity, const int step, const float scale,
    const float rintensity, const float rc, const float gc,
    const uint8_t boffset, const int depth, const int width,
    const uint8_t goffset, const float bc, const float max,
    const float bintensity, const float sbintensity, const float sgintensity,
    const float gintensity, uint16_t * ptr, const uint8_t roffset)
{
  for (int x = 0; x < width; x++)
    {
      float g = ptr[x * step + goffset] * scale;
      float b = ptr[x * step + boffset] * scale;
      float r = ptr[x * step + roffset] * scale;
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
      ptr[x * step + goffset] = av_clip_uintp2_c (g * max, depth);
      ptr[x * step + boffset] = av_clip_uintp2_c (b * max, depth);
      ptr[x * step + roffset] = av_clip_uintp2_c (r * max, depth);
}}
