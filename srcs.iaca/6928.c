#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int coef, int i, int t, int16_t * ptr2, int16_t * out,
    const int16_t * ptr1, int j)
{
  for (i = 30, j = 4; (i < 60) && (j > 0); i++)
    {
      t = *ptr1++;
      if (coef >= t)
	coef -= t;
      else
	{
	  out[i] = *ptr2++;
	  ptr1 += 30;
	  j--;
	}
    }
}
