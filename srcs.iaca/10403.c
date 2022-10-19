#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (int j, float *y, unsigned char *text, int i, float *x, int batch,
    int characters, size_t len, int steps, size_t *offsets)
{
  for (j = 0; j < steps; ++j)
    {
      unsigned char curr = text[(offsets[i]) % len];
      unsigned char next = text[(offsets[i] + 1) % len];
      x[(j * batch + i) * characters + curr] = 1;
      y[(j * batch + i) * characters + next] = 1;
      offsets[i] = (offsets[i] + 1) % len;
      if (curr > 255 || curr <= 0 || next > 255 || next <= 0)
	{
	  error ("Bad char");
	}
    }
}
