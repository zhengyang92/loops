#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, double w, double *w_data, int n2, int len, double c,
    const int32_t * data)
{
  IACA_START for (i = 0; i < n2; i++)
    {
      w = c - i - 1.0;
      w = 1.0 - (w * w);
      w_data[i] = data[i] * w;
      w_data[len - 1 - i] = data[len - 1 - i] * w;
     } IACA_END
}
