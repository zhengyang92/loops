#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int width, int32_t * b2, int32_t * b1, int32_t * b0)
{
  for (i = 0; i < width; i++)
    {
      b1[i] =
	((unsigned) (b1[i]) -
	 ((int) (113 * (b0[i] + (unsigned) b2[i]) + 64) >> 7));
}}
