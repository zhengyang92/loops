#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint16_t fixed_y_t;

int
fn (const fixed_y_t * src, fixed_y_t * dst, int w, int i)
{
  for (i = 0; i < w; ++i)
     { IACA_START
      const uint32_t R = GammaToLinearS (src[0 * w + i]);
      const uint32_t G = GammaToLinearS (src[1 * w + i]);
      const uint32_t B = GammaToLinearS (src[2 * w + i]);
      const uint32_t Y = RGBToGray (R, G, B);
      dst[i] = (fixed_y_t) LinearToGammaS (Y);
} IACA_END }
