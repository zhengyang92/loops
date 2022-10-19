#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *x, int i, int size, int c, int forward, int b, float *swap,
    int layers)
{
  for (i = 0; i < size; ++i)
    {
      int i1 = b * layers * size + c * size + i;
      int i2 = b * layers * size + i * layers + c;
      if (forward)
	swap[i2] = x[i1];
      else
	swap[i1] = x[i2];
    }
}
