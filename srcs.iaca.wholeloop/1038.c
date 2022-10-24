#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint64_t uint64_t;

int
fn (int y, int w, const float scaler, uint16_t * dst, int h, const int ddepth,
    const uint64_t * ptr, const int ptr_linesize, const uint16_t * rptr,
    const float minr)
{
  IACA_START for (int x = 0; x < w; x++)
    {
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
      uint64_t tl = ptr[(y - t) * ptr_linesize + x - l];
      uint64_t tr = ptr[(y - t) * ptr_linesize + x + r];
      uint64_t bl = ptr[(y + b) * ptr_linesize + x - l];
      uint64_t br = ptr[(y + b) * ptr_linesize + x + r];
      uint64_t ntl = ptr[(y - nt) * ptr_linesize + x - nl];
      uint64_t ntr = ptr[(y - nt) * ptr_linesize + x + nr];
      uint64_t nbl = ptr[(y + nb) * ptr_linesize + x - nl];
      uint64_t nbr = ptr[(y + nb) * ptr_linesize + x + nr];
      uint64_t div = (l + r) * (t + b);
      uint64_t ndiv = (nl + nr) * (nt + nb);
      uint64_t p0 = (br + tl - bl - tr) / div;
      uint64_t n0 = (nbr + ntl - nbl - ntr) / ndiv;
      dst[x] = av_clip_uintp2_c (lrintf (lerpf (p0, n0, factor)), ddepth);
}IACA_END}
