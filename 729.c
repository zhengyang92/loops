#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * yptr, uint16_t * vptr, uint16_t * uptr, const float rl,
    const float rd, const int chroma_w, const int depth, const int width,
    const float saturation, const float max, const float bd, const float bl,
    const float imax)
{
  for (int x = 0; x < width; x++)
    {
      float y = yptr[x * chroma_w] * imax;
      float u = uptr[x] * imax - .5f;
      float v = vptr[x] * imax - .5f;
      float nu, nv;
      nu = saturation * (u + y * bd + bl);
      nv = saturation * (v + y * rd + rl);
      uptr[x] = av_clip_uintp2_c ((nu + 0.5f) * max, depth);
      vptr[x] = av_clip_uintp2_c ((nv + 0.5f) * max, depth);
}}
