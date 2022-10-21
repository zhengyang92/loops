#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * darksrc, int w, int undershoot, const uint16_t * bsrc,
    const uint16_t * brightsrc, int overshoot, uint16_t * dst)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      dst[x] =
	((bsrc[x]) >
	 (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
      dst[x] =
	((dst[x]) >
	 (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
} IACA_END }
