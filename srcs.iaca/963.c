#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *asrc, int w, const float *msrc, int x, float *dst,
    float offsetf)
{
  for (x = 0; x < w; x++)
    {
      dst[x] = ((msrc[x] - offsetf) * asrc[x]) + offsetf;
    }
}
