#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * uptr, const float rl, const float rd, const int chroma_w,
    uint8_t * yptr, const int width, const float saturation, uint8_t * vptr,
    const float bd, const float max, const float bl, const float imax)
{
  IACA_START for (int x = 0; x < width; x++)
    {
      float y = yptr[x * chroma_w] * imax;
      float u = uptr[x] * imax - .5f;
      float v = vptr[x] * imax - .5f;
      float nu, nv;
      nu = saturation * (u + y * bd + bl);
      nv = saturation * (v + y * rd + rl);
      uptr[x] = av_clip_uint8_c ((nu + 0.5f) * max);
      vptr[x] = av_clip_uint8_c ((nv + 0.5f) * max);
}IACA_END}
