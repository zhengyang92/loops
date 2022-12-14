#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int E, int i, int I, int H, int wd, ptrdiff_t strideb, uint8_t * dst,
    ptrdiff_t stridea)
{
  IACA_START for (i = 0; i < 8; i++, dst += stridea)
    {
      int p7, p6, p5, p4;
      int p3 = dst[strideb * -4], p2 = dst[strideb * -3];
      int p1 = dst[strideb * -2], p0 = dst[strideb * -1];
      int q0 = dst[strideb * +0], q1 = dst[strideb * +1];
      int q2 = dst[strideb * +2], q3 = dst[strideb * +3];
      int q4, q5, q6, q7;
      int fm = ((p3 - p2) >= 0 ? (p3 - p2) : (-(p3 - p2))) <= I
	&& ((p2 - p1) >= 0 ? (p2 - p1) : (-(p2 - p1))) <= I
	&& ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) <= I
	&& ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) <= I
	&& ((q2 - q1) >= 0 ? (q2 - q1) : (-(q2 - q1))) <= I
	&& ((q3 - q2) >= 0 ? (q3 - q2) : (-(q3 - q2))) <= I
	&& ((p0 - q0) >=
	    0 ? (p0 - q0) : (-(p0 - q0))) * 2 + (((p1 - q1) >=
						  0 ? (p1 -
						       q1) : (-(p1 -
								q1))) >> 1) <=
	E;
      int flat8out, flat8in;
      if (!fm)
	continue;
      if (wd >= 16)
	{
	  p7 = dst[strideb * -8];
	  p6 = dst[strideb * -7];
	  p5 = dst[strideb * -6];
	  p4 = dst[strideb * -5];
	  q4 = dst[strideb * +4];
	  q5 = dst[strideb * +5];
	  q6 = dst[strideb * +6];
	  q7 = dst[strideb * +7];
	  flat8out = ((p7 - p0) >= 0 ? (p7 - p0) : (-(p7 - p0))) <= 1
	    && ((p6 - p0) >= 0 ? (p6 - p0) : (-(p6 - p0))) <= 1
	    && ((p5 - p0) >= 0 ? (p5 - p0) : (-(p5 - p0))) <= 1
	    && ((p4 - p0) >= 0 ? (p4 - p0) : (-(p4 - p0))) <= 1
	    && ((q4 - q0) >= 0 ? (q4 - q0) : (-(q4 - q0))) <= 1
	    && ((q5 - q0) >= 0 ? (q5 - q0) : (-(q5 - q0))) <= 1
	    && ((q6 - q0) >= 0 ? (q6 - q0) : (-(q6 - q0))) <= 1
	    && ((q7 - q0) >= 0 ? (q7 - q0) : (-(q7 - q0))) <= 1;
	}
      if (wd >= 8)
	flat8in = ((p3 - p0) >= 0 ? (p3 - p0) : (-(p3 - p0))) <= 1
	  && ((p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0))) <= 1
	  && ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) <= 1
	  && ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) <= 1
	  && ((q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0))) <= 1
	  && ((q3 - q0) >= 0 ? (q3 - q0) : (-(q3 - q0))) <= 1;
      if (wd >= 16 && flat8out && flat8in)
	{
	  dst[strideb * -7] =
	    (p7 + p7 + p7 + p7 + p7 + p7 + p7 + p6 * 2 + p5 + p4 + p3 + p2 +
	     p1 + p0 + q0 + 8) >> 4;
	  dst[strideb * -6] =
	    (p7 + p7 + p7 + p7 + p7 + p7 + p6 + p5 * 2 + p4 + p3 + p2 + p1 +
	     p0 + q0 + q1 + 8) >> 4;
	  dst[strideb * -5] =
	    (p7 + p7 + p7 + p7 + p7 + p6 + p5 + p4 * 2 + p3 + p2 + p1 + p0 +
	     q0 + q1 + q2 + 8) >> 4;
	  dst[strideb * -4] =
	    (p7 + p7 + p7 + p7 + p6 + p5 + p4 + p3 * 2 + p2 + p1 + p0 + q0 +
	     q1 + q2 + q3 + 8) >> 4;
	  dst[strideb * -3] =
	    (p7 + p7 + p7 + p6 + p5 + p4 + p3 + p2 * 2 + p1 + p0 + q0 + q1 +
	     q2 + q3 + q4 + 8) >> 4;
	  dst[strideb * -2] =
	    (p7 + p7 + p6 + p5 + p4 + p3 + p2 + p1 * 2 + p0 + q0 + q1 + q2 +
	     q3 + q4 + q5 + 8) >> 4;
	  dst[strideb * -1] =
	    (p7 + p6 + p5 + p4 + p3 + p2 + p1 + p0 * 2 + q0 + q1 + q2 + q3 +
	     q4 + q5 + q6 + 8) >> 4;
	  dst[strideb * +0] =
	    (p6 + p5 + p4 + p3 + p2 + p1 + p0 + q0 * 2 + q1 + q2 + q3 + q4 +
	     q5 + q6 + q7 + 8) >> 4;
	  dst[strideb * +1] =
	    (p5 + p4 + p3 + p2 + p1 + p0 + q0 + q1 * 2 + q2 + q3 + q4 + q5 +
	     q6 + q7 + q7 + 8) >> 4;
	  dst[strideb * +2] =
	    (p4 + p3 + p2 + p1 + p0 + q0 + q1 + q2 * 2 + q3 + q4 + q5 + q6 +
	     q7 + q7 + q7 + 8) >> 4;
	  dst[strideb * +3] =
	    (p3 + p2 + p1 + p0 + q0 + q1 + q2 + q3 * 2 + q4 + q5 + q6 + q7 +
	     q7 + q7 + q7 + 8) >> 4;
	  dst[strideb * +4] =
	    (p2 + p1 + p0 + q0 + q1 + q2 + q3 + q4 * 2 + q5 + q6 + q7 + q7 +
	     q7 + q7 + q7 + 8) >> 4;
	  dst[strideb * +5] =
	    (p1 + p0 + q0 + q1 + q2 + q3 + q4 + q5 * 2 + q6 + q7 + q7 + q7 +
	     q7 + q7 + q7 + 8) >> 4;
	  dst[strideb * +6] =
	    (p0 + q0 + q1 + q2 + q3 + q4 + q5 + q6 * 2 + q7 + q7 + q7 + q7 +
	     q7 + q7 + q7 + 8) >> 4;
	}
      else if (wd >= 8 && flat8in)
	{
	  dst[strideb * -3] = (p3 + p3 + p3 + 2 * p2 + p1 + p0 + q0 + 4) >> 3;
	  dst[strideb * -2] = (p3 + p3 + p2 + 2 * p1 + p0 + q0 + q1 + 4) >> 3;
	  dst[strideb * -1] = (p3 + p2 + p1 + 2 * p0 + q0 + q1 + q2 + 4) >> 3;
	  dst[strideb * +0] = (p2 + p1 + p0 + 2 * q0 + q1 + q2 + q3 + 4) >> 3;
	  dst[strideb * +1] = (p1 + p0 + q0 + 2 * q1 + q2 + q3 + q3 + 4) >> 3;
	  dst[strideb * +2] = (p0 + q0 + q1 + 2 * q2 + q3 + q3 + q3 + 4) >> 3;
	}
      else
	{
	  int hev = ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) > H
	    || ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) > H;
	  if (hev)
	    {
	      int f =
		av_clip_int8_c (3 * (q0 - p0) + av_clip_int8_c (p1 - q1));
	      int f1 = ((f + 4) > (127) ? (127) : (f + 4)) >> 3;
	      int f2 = ((f + 3) > (127) ? (127) : (f + 3)) >> 3;
	      dst[strideb * -1] = av_clip_uint8_c (p0 + f2);
	      dst[strideb * +0] = av_clip_uint8_c (q0 - f1);
	    }
	  else
	    {
	      int f = av_clip_int8_c (3 * (q0 - p0));
	      int f1 = ((f + 4) > (127) ? (127) : (f + 4)) >> 3;
	      int f2 = ((f + 3) > (127) ? (127) : (f + 3)) >> 3;
	      dst[strideb * -1] = av_clip_uint8_c (p0 + f2);
	      dst[strideb * +0] = av_clip_uint8_c (q0 - f1);
	      f = (f1 + 1) >> 1;
	      dst[strideb * -2] = av_clip_uint8_c (p1 + f);
	      dst[strideb * +1] = av_clip_uint8_c (q1 - f);
}IACA_END}}}
