#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *bo, const float scale, float *yb, float *ub, float *ro, float *go,
    float *vb)
{
  int yy = 0;
  for (int xx = 0; xx < 8; xx++)
    {
      const int idx = xx + yy * 8;
      convert (yb[idx], ub[idx], vb[idx], &bo[xx], &go[xx], &ro[xx]);
      bo[xx] = to_linear (bo[xx], scale);
      go[xx] = to_linear (go[xx], scale);
      ro[xx] = to_linear (ro[xx], scale);
}}
