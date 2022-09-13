#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (int j, float *y, int i, float *x, int batch, int characters, size_t len,
    int *tokens, int steps, size_t *offsets)
{
  for (j = 0; j < steps; ++j)
    {
      int curr = tokens[(offsets[i]) % len];
      int next = tokens[(offsets[i] + 1) % len];
      x[(j * batch + i) * characters + curr] = 1;
      y[(j * batch + i) * characters + next] = 1;
      offsets[i] = (offsets[i] + 1) % len;
      if (curr >= characters || curr < 0 || next >= characters || next < 0)
	{
	  error ("Bad char");
	}
    }
}
