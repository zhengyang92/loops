#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int buf_b[32], int k, int i, int32_t * output)
{
  for (i = 0, k = 31; i < 16; i++, k--)
    {
      output[i] = clip23 (buf_b[i] - buf_b[k]);
      output[16 + i] = clip23 (buf_b[i] + buf_b[k]);
    }
}
