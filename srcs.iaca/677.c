#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int mrefs, int w, int interpol, int x, int mrefs3, int prefs, int prefs3,
    const uint16_t coef_sp[2], uint16_t * cur, int clip_max, uint16_t * dst)
{
  for (x = 0; x < w; x++)
    {
      interpol =
	(coef_sp[0] * (cur[mrefs] + cur[prefs]) -
	 coef_sp[1] * (cur[mrefs3] + cur[prefs3])) >> 13;
      dst[0] = av_clip_c (interpol, 0, clip_max);
      dst++;
      cur++;
    }
}
