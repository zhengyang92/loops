#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * block, const int stride, unsigned int temp[8], int i)
{
  const int xStride = 16;
  for (i = 0; i < 4; i++)
    {
      temp[2 * i + 0] =
	block[stride * i + xStride * 0] + (unsigned) block[stride * i +
							   xStride * 1];
      temp[2 * i + 1] =
	block[stride * i + xStride * 0] - (unsigned) block[stride * i +
							   xStride * 1];
}}
