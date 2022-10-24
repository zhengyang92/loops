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
typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t dstep, int i, const int16_t * src0, int16_t * dst0,
    struct FFIIRFilterState *s, ptrdiff_t sstep,
    const struct FFIIRFilterCoeffs *c, int size)
{
  IACA_START for (i = 0; i < size; i++)
    {
      float in = *src0 * c->gain + s->x[0] * c->cy[0] + s->x[1] * c->cy[1];
      *dst0 = av_clip_int16_c (lrintf (s->x[0] + in + s->x[1] * c->cx[1]));
      s->x[0] = s->x[1];
      s->x[1] = in;
      src0 += sstep;
      dst0 += dstep;
}IACA_END}
