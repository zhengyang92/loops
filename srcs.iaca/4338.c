#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const float scale, const float preserve, const float rc, const int depth,
    uint16_t * bptr, const int width, uint16_t * rptr, const float max,
    uint16_t * gptr, const float gmw, const float rcw, const float by,
    const float byw, const float gm)
{
  for (int x = 0; x < width; x++)
    {
      float g = gptr[x];
      float b = bptr[x];
      float r = rptr[x];
      float g0, g1, g2;
      float b0, b1, b2;
      float r0, r1, r2;
      float gd, bd, rd;
      float gb, br, rg;
      float nr, ng, nb;
      float li, lo, lf;
      br = (b + r) * 0.5f;
      gb = (g + b) * 0.5f;
      rg = (r + g) * 0.5f;
      gd = g - br;
      bd = b - rg;
      rd = r - gb;
      g0 = g + gd * gm;
      b0 = b - gd * gm;
      r0 = r - gd * gm;
      g1 = g - bd * by;
      b1 = b + bd * by;
      r1 = r - bd * by;
      g2 = g - rd * rc;
      b2 = b - rd * rc;
      r2 = r + rd * rc;
      ng = av_clipf_sse ((g0 * gmw + g1 * byw + g2 * rcw) * scale, 0.f, max);
      nb = av_clipf_sse ((b0 * gmw + b1 * byw + b2 * rcw) * scale, 0.f, max);
      nr = av_clipf_sse ((r0 * gmw + r1 * byw + r2 * rcw) * scale, 0.f, max);
      li =
	((((r) > (g) ? (r) : (g))) >
	 (b) ? (((r) > (g) ? (r) : (g))) : (b)) + ((((r) > (g) ? (g) : (r))) >
						   (b) ? (b)
						   : (((r) >
						       (g) ? (g) : (r))));
      lo =
	((((nr) > (ng) ? (nr) : (ng))) >
	 (nb) ? (((nr) > (ng) ? (nr) : (ng))) : (nb)) +
	((((nr) > (ng) ? (ng) : (nr))) >
	 (nb) ? (nb) : (((nr) > (ng) ? (ng) : (nr)))) + 1.19209290e-7F;
      lf = li / lo;
      r = nr * lf;
      g = ng * lf;
      b = nb * lf;
      nr = lerpf (nr, r, preserve);
      ng = lerpf (ng, g, preserve);
      nb = lerpf (nb, b, preserve);;
      gptr[x] = av_clip_uintp2_c (ng, depth);
      bptr[x] = av_clip_uintp2_c (nb, depth);
      rptr[x] = av_clip_uintp2_c (nr, depth);
}}
