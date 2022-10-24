#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int dfactor, int dshift, int32_t * p2, int length, int32_t * p1)
{
  IACA_START for (i = 0; i < length; i++)
    {
      int32_t a = p1[i];
      int32_t b = p2[i];
      b =
	(unsigned) ((int) (dfactor * (unsigned) (b >> dshift) + 128) >> 8) <<
	dshift;
      p1[i] = b - a;
}IACA_END}
