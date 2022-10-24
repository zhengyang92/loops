#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int nsample, float *su1, float *su2, int band)
{
  IACA_START for (; nsample < band + 256; nsample++)
    {
      float c1 = su1[nsample];
      float c2 = su2[nsample];
      su1[nsample] = c1 + c2;
      su2[nsample] = c1 - c2;
}IACA_END}
