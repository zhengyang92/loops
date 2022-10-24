#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * b2, int i, int16_t * b1, int16_t * b4, int width, int16_t * b3,
    int16_t * b0)
{
  IACA_START for (i = 0; i < width; i++)
    {
      b2[i] =
	(int) (((unsigned) (b2[i]) -
		((int) (9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 16) >> 5)));
}IACA_END}
