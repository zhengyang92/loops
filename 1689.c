#include <stdint.h>
#include <stdio.h>






int
fn (float *su2, float w[2][2], int nsample, int band, float *su1)
{
  for (nsample = band; nsample < band + 8; nsample++)
    {
      su1[nsample] *=
	((w[0][0]) + (nsample - band) * 0.125 * ((w[0][1]) - (w[0][0])));
      su2[nsample] *=
	((w[1][0]) + (nsample - band) * 0.125 * ((w[1][1]) - (w[1][0])));
    }
}
