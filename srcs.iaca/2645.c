#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct FFIIRFilterCoeffs
{
  int order;
  float gain;
  int *cx;
  float *cy;
} FFIIRFilterCoeffs;
typedef struct FFIIRFilterState
{
  float x[1];
} FFIIRFilterState;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t dstep, int i, struct FFIIRFilterState *s, const float *src0,
    const struct FFIIRFilterCoeffs *c, float *dst0, ptrdiff_t sstep, int size)
{
  for (i = 0; i < size; i++)
     { IACA_START
      float in = *src0 * c->gain + s->x[0] * c->cy[0] + s->x[1] * c->cy[1];
      *dst0 = s->x[0] + in + s->x[1] * c->cx[1];
      s->x[0] = s->x[1];
      s->x[1] = in;
      src0 += sstep;
      dst0 += dstep;
} IACA_END }
