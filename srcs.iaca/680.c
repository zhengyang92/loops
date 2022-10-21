#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, const int in_linesize, const int w, const float strength,
    const int y1, const int y0, const uint8_t * src, const int w1,
    uint8_t * dst)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      const int x0 = ((x - 1) > (0) ? (x - 1) : (0));
      const int x1 = ((x + 1) > (w1) ? (w1) : (x + 1));
      int a = src[y0 * in_linesize + x0];
      int b = src[y0 * in_linesize + x];
      int c = src[y0 * in_linesize + x1];
      int d = src[y * in_linesize + x0];
      int e = src[y * in_linesize + x];
      int f = src[y * in_linesize + x1];
      int g = src[y1 * in_linesize + x0];
      int h = src[y1 * in_linesize + x];
      int i = src[y1 * in_linesize + x1];
      int mn, mn2, mx, mx2;
      float amp, weight;
      mn =
	((((((((d) > (e) ? (e) : (d))) >
	     (f) ? (f) : (((d) > (e) ? (e) : (d))))) >
	   (b) ? (b)
	   : (((((d) > (e) ? (e) : (d))) >
	       (f) ? (f) : (((d) > (e) ? (e) : (d))))))) >
	 (h) ? (h)
	 : (((((((d) > (e) ? (e) : (d))) >
	       (f) ? (f) : (((d) > (e) ? (e) : (d))))) >
	     (b) ? (b)
	     : (((((d) > (e) ? (e) : (d))) >
		 (f) ? (f) : (((d) > (e) ? (e) : (d))))))));
      mn2 =
	((((((((mn) > (a) ? (a) : (mn))) >
	     (c) ? (c) : (((mn) > (a) ? (a) : (mn))))) >
	   (g) ? (g)
	   : (((((mn) > (a) ? (a) : (mn))) >
	       (c) ? (c) : (((mn) > (a) ? (a) : (mn))))))) >
	 (i) ? (i)
	 : (((((((mn) > (a) ? (a) : (mn))) >
	       (c) ? (c) : (((mn) > (a) ? (a) : (mn))))) >
	     (g) ? (g)
	     : (((((mn) > (a) ? (a) : (mn))) >
		 (c) ? (c) : (((mn) > (a) ? (a) : (mn))))))));
      mn = mn + mn2;
      mx =
	((((((((d) > (e) ? (d) : (e))) >
	     (f) ? (((d) > (e) ? (d) : (e))) : (f))) >
	   (b)
	   ? (((((d) > (e) ? (d) : (e))) >
	       (f) ? (((d) > (e) ? (d) : (e))) : (f))) : (b))) >
	 (h)
	 ? (((((((d) > (e) ? (d) : (e))) >
	       (f) ? (((d) > (e) ? (d) : (e))) : (f))) >
	     (b)
	     ? (((((d) > (e) ? (d) : (e))) >
		 (f) ? (((d) > (e) ? (d) : (e))) : (f))) : (b))) : (h));
      mx2 =
	((((((((mx) > (a) ? (mx) : (a))) >
	     (c) ? (((mx) > (a) ? (mx) : (a))) : (c))) >
	   (g)
	   ? (((((mx) > (a) ? (mx) : (a))) >
	       (c) ? (((mx) > (a) ? (mx) : (a))) : (c))) : (g))) >
	 (i)
	 ? (((((((mx) > (a) ? (mx) : (a))) >
	       (c) ? (((mx) > (a) ? (mx) : (a))) : (c))) >
	     (g)
	     ? (((((mx) > (a) ? (mx) : (a))) >
		 (c) ? (((mx) > (a) ? (mx) : (a))) : (c))) : (g))) : (i));
      mx = mx + mx2;
      amp =
	sqrtf (av_clipf_sse
	       (((mn) > (511 - mx) ? (511 - mx) : (mn)) / (float) mx, 0.f,
		1.f));
      weight = amp / strength;
      dst[x] =
	av_clip_uint8_c (((b + d + f + h) * weight + e) / (1.f +
							   4.f * weight));
} IACA_END }
