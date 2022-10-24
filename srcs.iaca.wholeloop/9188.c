#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (int16_t * samples, int i, int len, int32_t ** in, int shift)
{
  IACA_START for (i = 0; i < len; i++)
    {
      int a = in[0][i];
      int b = in[1][i];
      (*samples++) = (a + b) << shift;
      (*samples++) = b << shift;
}IACA_END}
