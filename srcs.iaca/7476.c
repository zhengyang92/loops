#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct ColorSystem
{
  float xRed, yRed, xGreen, yGreen, xBlue, yBlue, xWhite, yWhite, gamma;
} ColorSystem;
typedef __uint16_t uint16_t;

int
fn (uint16_t * const pixels, int UCS, int LUV, int y, const int correct_gamma,
    const int linesize, const struct ColorSystem *const cs, int leftEdge,
    const int cie, int x, const int w, const float (*m)[3],
    const uint16_t maxval, const float contrast, int rightEdge, const int h,
    int XYY)
{
  for (x = leftEdge; x <= rightEdge; ++x)
    {
      float cx, cy, cz, jr, jg, jb, jmax;
      int r, g, b, mx = maxval;
      if (cie == LUV)
	{
	  float up, vp;
	  up = ((float) x) / (w - 1);
	  vp = 1.0 - ((float) y) / (h - 1);
	  upvp_to_xy (up, vp, &cx, &cy);
	  cz = 1.0 - (cx + cy);
	}
      else if (cie == UCS)
	{
	  float u, v;
	  u = ((float) x) / (w - 1);
	  v = 1.0 - ((float) y) / (h - 1);
	  uv_to_xy (u, v, &cx, &cy);
	  cz = 1.0 - (cx + cy);
	}
      else if (cie == XYY)
	{
	  cx = ((float) x) / (w - 1);
	  cy = 1.0 - ((float) y) / (h - 1);
	  cz = 1.0 - (cx + cy);
	}
      else
	{
	  do
	    {
	      if (!(0))
		{
		  av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
			  "0", "program.c", 1152);
		  abort ();
		}
	    }
	  while (0);
	}
      xyz_to_rgb (m, cx, cy, cz, &jr, &jg, &jb);
      if (constrain_rgb (&jr, &jg, &jb))
	mx *= contrast;
      jmax =
	((((jr) > (jg) ? (jr) : (jg))) >
	 (jb) ? (((jr) > (jg) ? (jr) : (jg))) : (jb));
      if (jmax > 0)
	{
	  jr = jr / jmax;
	  jg = jg / jmax;
	  jb = jb / jmax;
	}
      if (correct_gamma)
	gamma_correct_rgb (cs, &jr, &jg, &jb);
      r = mx * jr;
      g = mx * jg;
      b = mx * jb;
      pixels[y * linesize + x * 4 + 0] = r;
      pixels[y * linesize + x * 4 + 1] = g;
      pixels[y * linesize + x * 4 + 2] = b;
      pixels[y * linesize + x * 4 + 3] = 65535;
    }
}
