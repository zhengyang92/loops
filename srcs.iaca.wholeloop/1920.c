#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int threshold1, int i, int last_non_zero, int start_i,
    int16_t * block, unsigned int threshold2, const uint8_t * scantable,
    const int *qmat, int level, int j)
{
  IACA_START for (i = 63; i >= start_i; i--)
    {
      j = scantable[i];
      level = block[j] * qmat[j];
      if (((unsigned) (level + threshold1)) > threshold2)
	{
	  last_non_zero = i;
	  break;
	}
      else
	{
	  block[j] = 0;
	}
     } IACA_END
}
