#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int k, int i, int buf_b[64], int32_t * output)
{
  IACA_START for (i = 0, k = 63; i < 32; i++, k--)
    {
      output[i] = clip23 (buf_b[i] - buf_b[k]);
      output[32 + i] = clip23 (buf_b[i] + buf_b[k]);
     } IACA_END
}
