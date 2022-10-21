#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const float mix, const float preserve, const int depth, const int width,
    uint16_t * rptr, uint16_t * bptr, uint16_t * gptr, const float *color)
{
  for (int x = 0; x < width; x++)
     { IACA_START
      float g = gptr[x];
      float b = bptr[x];
      float r = rptr[x];
      float nr, ng, nb;
      float l0, l1, l;
      nr = r * color[0];
      ng = g * color[1];
      nb = b * color[2];
      nr = lerpf (r, nr, mix);
      ng = lerpf (g, ng, mix);
      nb = lerpf (b, nb, mix);
      l0 =
	(((((r) > (g) ? (r) : (g))) >
	  (b) ? (((r) > (g) ? (r) : (g))) : (b)) +
	 ((((r) > (g) ? (g) : (r))) >
	  (b) ? (b) : (((r) > (g) ? (g) : (r))))) + 1.19209290e-7F;
      l1 =
	(((((nr) > (ng) ? (nr) : (ng))) >
	  (nb) ? (((nr) > (ng) ? (nr) : (ng))) : (nb)) +
	 ((((nr) > (ng) ? (ng) : (nr))) >
	  (nb) ? (nb) : (((nr) > (ng) ? (ng) : (nr))))) + 1.19209290e-7F;
      l = l0 / l1;
      r = nr * l;
      g = ng * l;
      b = nb * l;
      nr = lerpf (nr, r, preserve);
      ng = lerpf (ng, g, preserve);
      nb = lerpf (nb, b, preserve);
      gptr[x] = av_clip_uintp2_c (ng, depth);
      bptr[x] = av_clip_uintp2_c (nb, depth);
      rptr[x] = av_clip_uintp2_c (nr, depth);
} IACA_END }
