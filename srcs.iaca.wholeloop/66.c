#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const double *in, int length, double mean)
{
  double sum = 0.;
  IACA_START for (int i = 0; i < length; i++)
    {
      sum += sqr (in[i] - mean);
}IACA_END}
