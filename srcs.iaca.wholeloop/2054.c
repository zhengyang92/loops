#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int len, int32_t ** in, int shift, int32_t ** samples)
{
  IACA_START for (i = 0; i < len; i++)
    {
      unsigned a = in[0][i];
      unsigned b = in[1][i];
      (samples[0][i]) = (a + b) << shift;
      (samples[1][i]) = b << shift;
}IACA_END}
