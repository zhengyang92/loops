#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint16_t fixed_y_t;

int
fn (int w, fixed_y_t * y, const fixed_y_t * rgb, int i)
{
  IACA_START for (i = 0; i < w; ++i)
    {
      y[i] = RGBToGray (rgb[0 * w + i], rgb[1 * w + i], rgb[2 * w + i]);
     } IACA_END
}
