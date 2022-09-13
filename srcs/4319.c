#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int cbh, const int dvy, const int w, uint16_t * du,
    const uint16_t * sv, const int duy, uint16_t * dv, const uint16_t * su,
    const int crh)
{
  for (int x = 0; x < w; x++)
    {
      du[x] = su[av_clip_c (x - cbh, 0, w - 1) + duy];
      dv[x] = sv[av_clip_c (x - crh, 0, w - 1) + dvy];
}}
