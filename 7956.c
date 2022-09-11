#include <stdint.h>
#include <stdio.h>




typedef struct FFIIRFilterCoeffs
{
  int order;
  float gain;
  int *cx;
  float *cy;
} FFIIRFilterCoeffs;

int
fn (struct FFIIRFilterCoeffs *c, int order, int i, double p[31][2])
{
  for (i = 0; i < order; i++)
    {
      c->gain += p[i][0];
      c->cy[i] =
	(-p[i][0] * p[order][0] +
	 -p[i][1] * p[order][1]) / (p[order][0] * p[order][0] +
				    p[order][1] * p[order][1]);
    }
}
