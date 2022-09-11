#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef int16_t fixed_t;

int
fn (int i, const int uv_w, const fixed_t * best_uv, uint8_t * dst_u,
    uint8_t * dst_v)
{
  for (i = 0; i < uv_w; ++i)
    {
      const int off = i;
      const int r = best_uv[off + 0 * uv_w];
      const int g = best_uv[off + 1 * uv_w];
      const int b = best_uv[off + 2 * uv_w];
      dst_u[i] = ConvertRGBToU (r, g, b);
      dst_v[i] = ConvertRGBToV (r, g, b);
}}
