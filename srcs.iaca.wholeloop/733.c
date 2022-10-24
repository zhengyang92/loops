#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const float mix, const float preserve, const int width, uint8_t * bptr,
    uint8_t * gptr, uint8_t * rptr, const float *color)
{
  IACA_START for (int x = 0; x < width; x++)
    {
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
      gptr[x] = av_clip_uint8_c (ng);
      bptr[x] = av_clip_uint8_c (nb);
      rptr[x] = av_clip_uint8_c (nr);
}IACA_END}
