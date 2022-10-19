#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, float *Y, int NY, int i, float *OUT)
{
  int index = 0;
  for (i = 0; i < NY; ++i)
    {
      if (Y)
	Y[j * NY + i] += OUT[index];
      ++index;
    }
}
