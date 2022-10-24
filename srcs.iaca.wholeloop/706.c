#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct ColorSystem
{
  float xRed, yRed, xGreen, yGreen, xBlue, yBlue, xWhite, yWhite, gamma;
} ColorSystem;
typedef __uint16_t uint16_t;

int
fn (int gamuts, int UCS, int w, int i, uint16_t * pixels, int XYY, int h,
    const struct ColorSystem color_systems[10], int NB_CS, int linesize,
    int cie, int LUV)
{
  IACA_START for (i = 0; i < NB_CS; i++)
    {
      const struct ColorSystem *cs = &color_systems[i];
      int rx, ry, gx, gy, bx, by;
      if (!((1 << i) & gamuts))
	continue;
      if (cie == LUV)
	{
	  float wup, wvp;
	  xy_to_upvp (cs->xRed, cs->yRed, &wup, &wvp);
	  rx = (w - 1) * wup;
	  ry = (h - 1) - ((int) ((h - 1) * wvp));
	  xy_to_upvp (cs->xGreen, cs->yGreen, &wup, &wvp);
	  gx = (w - 1) * wup;
	  gy = (h - 1) - ((int) ((h - 1) * wvp));
	  xy_to_upvp (cs->xBlue, cs->yBlue, &wup, &wvp);
	  bx = (w - 1) * wup;
	  by = (h - 1) - ((int) ((h - 1) * wvp));
	}
      else if (cie == UCS)
	{
	  float wu, wv;
	  xy_to_uv (cs->xRed, cs->yRed, &wu, &wv);
	  rx = (w - 1) * wu;
	  ry = (h - 1) - ((int) ((h - 1) * wv));
	  xy_to_uv (cs->xGreen, cs->yGreen, &wu, &wv);
	  gx = (w - 1) * wu;
	  gy = (h - 1) - ((int) ((h - 1) * wv));
	  xy_to_uv (cs->xBlue, cs->yBlue, &wu, &wv);
	  bx = (w - 1) * wu;
	  by = (h - 1) - ((int) ((h - 1) * wv));
	}
      else if (cie == XYY)
	{
	  rx = (w - 1) * cs->xRed;
	  ry = (h - 1) - ((int) ((h - 1) * cs->yRed));
	  gx = (w - 1) * cs->xGreen;
	  gy = (h - 1) - ((int) ((h - 1) * cs->yGreen));
	  bx = (w - 1) * cs->xBlue;
	  by = (h - 1) - ((int) ((h - 1) * cs->yBlue));
	}
      else
	{
	  do
	    {
	      if (!(0))
		{
		  av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
			  "0", "program.c", 1369);
		  abort ();
		}
	    }
	  while (0);
	}
      draw_rline (pixels, linesize, rx, ry, gx, gy, w, h);
      draw_rline (pixels, linesize, gx, gy, bx, by, w, h);
      draw_rline (pixels, linesize, bx, by, rx, ry, w, h);
     } IACA_END
}
