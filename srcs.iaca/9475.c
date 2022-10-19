#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float w1, float w1_prev, int n1, float w0, float *l, int i, float w0_prev,
    float *mid, float *side, float *r)
{
  for (i = 0; i < n1; i++)
    {
      float interp0 = w0_prev + i * (w0 - w0_prev) / n1;
      float interp1 = w1_prev + i * (w1 - w1_prev) / n1;
      float p0 = 0.25 * (mid[i - 2] + 2 * mid[i - 1] + mid[i]);
      l[i] =
	av_clipf_c ((1 + interp1) * mid[i - 1] + side[i - 1] + interp0 * p0,
		    -1.0, 1.0);
      r[i] =
	av_clipf_c ((1 - interp1) * mid[i - 1] - side[i - 1] - interp0 * p0,
		    -1.0, 1.0);
}}
