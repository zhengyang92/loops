#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, float *y, int i, float *x, int batch, int index, int characters,
    char **source, int steps, char **dest)
{
  for (j = 0; j < steps; ++j)
     { IACA_START
      unsigned char curr = source[index][j];
      unsigned char next = dest[index][j];
      x[(j * batch + i) * characters + curr] = 1;
      y[(j * batch + i) * characters + next] = 1;
      if (curr > 255 || curr <= 0 || next > 255 || next <= 0)
	{
	  error ("Bad char");
	}
     } IACA_END
}
