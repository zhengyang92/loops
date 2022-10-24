#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int overlap, const float *window, float xx[864], int n, const float *x)
{
  IACA_START for (int i = 0; i < overlap; i++)
    {
      xx[i] = x[i] * window[i];
      xx[n - i - 1] = x[n - i - 1] * window[i];
}IACA_END}
