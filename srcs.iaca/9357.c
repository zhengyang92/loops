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
typedef __int16_t int16_t;

int
fn (ptrdiff_t dstep, int i, const int16_t * src0, int16_t * dst0,
    struct FFIIRFilterState *s, ptrdiff_t sstep,
    const struct FFIIRFilterCoeffs *c, int size)
{
  for (i = 0; i < size; i += 4)
     { IACA_START
      float in, res;
      in =
	*src0 * c->gain + c->cy[0] * s->x[0] + c->cy[1] * s->x[1] +
	c->cy[2] * s->x[2] + c->cy[3] * s->x[3];
      res = (s->x[0] + in) * 1 + (s->x[1] + s->x[3]) * 4 + s->x[2] * 6;
      *dst0 = av_clip_int16_c (lrintf (res));
      s->x[0] = in;
      src0 += sstep;
      dst0 += dstep;;
      in =
	*src0 * c->gain + c->cy[0] * s->x[1] + c->cy[1] * s->x[2] +
	c->cy[2] * s->x[3] + c->cy[3] * s->x[0];
      res = (s->x[1] + in) * 1 + (s->x[2] + s->x[0]) * 4 + s->x[3] * 6;
      *dst0 = av_clip_int16_c (lrintf (res));
      s->x[1] = in;
      src0 += sstep;
      dst0 += dstep;;
      in =
	*src0 * c->gain + c->cy[0] * s->x[2] + c->cy[1] * s->x[3] +
	c->cy[2] * s->x[0] + c->cy[3] * s->x[1];
      res = (s->x[2] + in) * 1 + (s->x[3] + s->x[1]) * 4 + s->x[0] * 6;
      *dst0 = av_clip_int16_c (lrintf (res));
      s->x[2] = in;
      src0 += sstep;
      dst0 += dstep;;
      in =
	*src0 * c->gain + c->cy[0] * s->x[3] + c->cy[1] * s->x[0] +
	c->cy[2] * s->x[1] + c->cy[3] * s->x[2];
      res = (s->x[3] + in) * 1 + (s->x[0] + s->x[2]) * 4 + s->x[1] * 6;
      *dst0 = av_clip_int16_c (lrintf (res));
      s->x[3] = in;
      src0 += sstep;
      dst0 += dstep;;
} IACA_END }
