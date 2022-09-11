#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int undershoot, const uint8_t * darksrc, const uint8_t * brightsrc,
    const uint8_t * bsrc, uint8_t * dst, int overshoot)
{
  for (int x = 0; x < w; x++)
    {
      dst[x] =
	((bsrc[x]) >
	 (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
      dst[x] =
	((dst[x]) >
	 (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
}}
