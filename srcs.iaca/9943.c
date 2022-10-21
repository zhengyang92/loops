#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int width, const uint8_t * in, const uint8_t * preds, int inverse,
    uint8_t * out, int stride)
{
  for (w = 1; w < width; ++w)
     { IACA_START
      const int pred =
	GradientPredictor_C (preds[w - 1], preds[w - stride],
			     preds[w - stride - 1]);
      out[w] = in[w] + (inverse ? pred : -pred);
} IACA_END }
