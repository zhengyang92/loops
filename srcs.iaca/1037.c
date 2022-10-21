#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int y, int w, const float scaler, int h, const int ddepth,
    const uint8_t * rptr, const int ptr_linesize, const uint32_t * ptr,
    uint8_t * dst, const float minr)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      const float radiusf =
	minr +
	(((0.f) >
	  (2 * rptr[x] + 1 - minr) ? (0.f) : (2 * rptr[x] + 1 -
					      minr))) * scaler;
      const int radius = floorf (radiusf);
      const float factor = radiusf - radius;
      const int nradius = radius + 1;
      const int l = ((radius) > (x) ? (x) : (radius));
      const int r = ((radius) > (w - x - 1) ? (w - x - 1) : (radius));
      const int t = ((radius) > (y) ? (y) : (radius));
      const int b = ((radius) > (h - y - 1) ? (h - y - 1) : (radius));
      const int nl = ((nradius) > (x) ? (x) : (nradius));
      const int nr = ((nradius) > (w - x - 1) ? (w - x - 1) : (nradius));
      const int nt = ((nradius) > (y) ? (y) : (nradius));
      const int nb = ((nradius) > (h - y - 1) ? (h - y - 1) : (nradius));
      uint32_t tl = ptr[(y - t) * ptr_linesize + x - l];
      uint32_t tr = ptr[(y - t) * ptr_linesize + x + r];
      uint32_t bl = ptr[(y + b) * ptr_linesize + x - l];
      uint32_t br = ptr[(y + b) * ptr_linesize + x + r];
      uint32_t ntl = ptr[(y - nt) * ptr_linesize + x - nl];
      uint32_t ntr = ptr[(y - nt) * ptr_linesize + x + nr];
      uint32_t nbl = ptr[(y + nb) * ptr_linesize + x - nl];
      uint32_t nbr = ptr[(y + nb) * ptr_linesize + x + nr];
      uint32_t div = (l + r) * (t + b);
      uint32_t ndiv = (nl + nr) * (nt + nb);
      uint32_t p0 = (br + tl - bl - tr) / div;
      uint32_t n0 = (nbr + ntl - nbl - ntr) / ndiv;
      dst[x] = av_clip_uintp2_c (lrintf (lerpf (p0, n0, factor)), ddepth);
} IACA_END }
