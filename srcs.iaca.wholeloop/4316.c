#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int stepw, int y, int sv, int yy, int su, const int w,
    const int thres_y, const int chroma_w, const int cy,
    const uint8_t * in_vptr, const uint8_t * in_yptr, const int cv,
    const int sizew, const int thres, const int thres_u, const int cu,
    const uint8_t * in_uptr, const int thres_v)
{
  int cn = 1;
  int x = 0;
  IACA_START for (int xx = ((0) > (x - sizew) ? (0) : (x - sizew));
       xx <= ((x + sizew) > (w - 1) ? (w - 1) : (x + sizew)); xx += stepw)
    {
      const int Y = in_yptr[xx * chroma_w];
      const int U = in_uptr[xx];
      const int V = in_vptr[xx];
      const int cyY = ((cy - Y) >= 0 ? (cy - Y) : (-(cy - Y)));
      const int cuU = ((cu - U) >= 0 ? (cu - U) : (-(cu - U)));
      const int cvV = ((cv - V) >= 0 ? (cv - V) : (-(cv - V)));
      if ((sqrtf ((cyY) * (cyY) + (cuU) * (cuU) + (cvV) * (cvV))) < thres
	  && cuU < thres_u && cvV < thres_v && cyY < thres_y && xx != x
	  && yy != y)
	{
	  su += U;
	  sv += V;
	  cn++;
	}
     } IACA_END
}
