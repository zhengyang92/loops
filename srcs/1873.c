#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * b2, int i, int16_t * b1, int width, int16_t * b0)
{
  for (i = 0; i < width; i++)
    {
      b1[i] =
	((unsigned) (b1[i]) +
	 ((int) (6497 * (b0[i] + (unsigned) b2[i]) + 2048) >> 12));
}}
