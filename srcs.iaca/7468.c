#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int stepw, int y, int sv, const uint16_t * in_vptr,
    const uint16_t * in_uptr, int yy, int su, const int thres_y, const int w,
    const int chroma_w, const int cy, const int cv, const int thres,
    const uint16_t * in_yptr, const int thres_u, const int cu,
    const int sizew, const int thres_v)
{
  int cn = 1;
  int x = 0;
  for (int xx = ((0) > (x - sizew) ? (0) : (x - sizew));
       xx <= ((x + sizew) > (w - 1) ? (w - 1) : (x + sizew)); xx += stepw)
    {
      const int64_t Y = in_yptr[xx * chroma_w];
      const int64_t U = in_uptr[xx];
      const int64_t V = in_vptr[xx];
      const int64_t cyY = ((cy - Y) >= 0 ? (cy - Y) : (-(cy - Y)));
      const int64_t cuU = ((cu - U) >= 0 ? (cu - U) : (-(cu - U)));
      const int64_t cvV = ((cv - V) >= 0 ? (cv - V) : (-(cv - V)));
      if ((sqrtf ((cyY) * (cyY) + (cuU) * (cuU) + (cvV) * (cvV))) < thres
	  && cuU < thres_u && cvV < thres_v && cyY < thres_y && xx != x
	  && yy != y)
	{
	  su += U;
	  sv += V;
	  cn++;
	}
    }
}
