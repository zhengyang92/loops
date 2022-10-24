#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, float *X, float *OUT, int NX)
{
  int index = 0;
  IACA_START for (i = 0; i < NX; ++i)
    {
      if (X)
	X[j * NX + i] += OUT[index];
      ++index;
     } IACA_END
}
