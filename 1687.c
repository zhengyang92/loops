#include <stdint.h>
#include <stdio.h>






int
fn (int nsample, float *su1, float *su2, int band)
{
  for (; nsample < band + 256; nsample++)
    {
      float c1 = su1[nsample];
      float c2 = su2[nsample];
      su1[nsample] = (c1 + c2) * 2.0;
      su2[nsample] = c2 * -2.0;
}}
