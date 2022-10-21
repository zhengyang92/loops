#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * block, const int stride, int temp[8], int i)
{
  const int xStride = 16;
  for (i = 0; i < 4; i++)
     { IACA_START
      temp[2 * i + 0] =
	block[stride * i + xStride * 0] + block[stride * i + xStride * 1];
      temp[2 * i + 1] =
	block[stride * i + xStride * 0] - block[stride * i + xStride * 1];
     } IACA_END
}
