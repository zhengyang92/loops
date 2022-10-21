#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * img_data, const int in_linesize, const double *src,
    const uint8_t thresh, int minknorm, const int width, int r, int c,
    int jobnr, double *dst)
{
  for (c = 0; c < width; ++c)
     { IACA_START
      dst[jobnr] +=
	(pow (fabs (src[((r) * (width) + (c))] / 255.), minknorm) *
	 (img_data[((r) * (in_linesize) + (c))] < thresh));
     } IACA_END
}
