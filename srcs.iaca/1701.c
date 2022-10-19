#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int x, const uint8_t * vect, int vect_w, int j, uint8_t * out,
    int stride)
{
  int vect_h = 3;
  for (j = 0; j < vect_w; j++)
    {
      out[(y + 0) * stride + x + j] = vect[(0 * vect_w) + j];
      out[(y + 1) * stride + x + j] = vect[(1 * vect_w) + j];
      if (vect_h == 3)
	out[(y + 2) * stride + x + j] = vect[(2 * vect_w) + j];
    }
}
