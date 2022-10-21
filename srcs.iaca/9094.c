#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *su2, int nsample, int band, float mc2_r, float mc1_l, float *su1,
    float mc1_r, float mc2_l)
{
  for (; nsample < band + 8; nsample++)
     { IACA_START
      float c1 = su1[nsample];
      float c2 = su2[nsample];
      c2 =
	c1 * ((mc1_l) + (nsample - band) * 0.125 * ((mc2_l) - (mc1_l))) +
	c2 * ((mc1_r) + (nsample - band) * 0.125 * ((mc2_r) - (mc1_r)));
      su1[nsample] = c2;
      su2[nsample] = c1 * 2.0 - c2;
} IACA_END }
