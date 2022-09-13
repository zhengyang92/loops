#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint16_t * ptr, const float *color, const uint8_t roffset,
    const float mix, const float preserve, const int depth, const int width,
    const uint8_t goffset, const uint8_t boffset, const int step)
{
  for (int x = 0; x < width; x++)
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
      ptr[x * step + goffset] = av_clip_uintp2_c (ng, depth);
      ptr[x * step + boffset] = av_clip_uintp2_c (nb, depth);
      ptr[x * step + roffset] = av_clip_uintp2_c (nr, depth);
}}
