#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, const uint8_t roffset, const int step, const float mix,
    const float preserve, const int width, const uint8_t goffset,
    const uint8_t boffset, const float *color)
{
  IACA_START for (int x = 0; x < width; x++)
    {
      float g = ptr[x * step + goffset];
      float b = ptr[x * step + boffset];
      float r = ptr[x * step + roffset];
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
      ptr[x * step + goffset] = av_clip_uint8_c (ng);
      ptr[x * step + boffset] = av_clip_uint8_c (nb);
      ptr[x * step + roffset] = av_clip_uint8_c (nr);
}IACA_END}
