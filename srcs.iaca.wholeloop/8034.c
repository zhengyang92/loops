#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int threshold1, int i, int last_non_zero, int coeff[2][64],
    int start_i, int16_t * block, unsigned int threshold2,
    const uint8_t * scantable, const int *qmat, int coeff_count[64])
{
  int max = 0;
  int bias = 0;
  IACA_START for (i = start_i; i <= last_non_zero; i++)
    {
      const int j = scantable[i];
      int level = block[j] * qmat[j];
      if (((unsigned) (level + threshold1)) > threshold2)
	{
	  if (level > 0)
	    {
	      level = (bias + level) >> 21;
	      coeff[0][i] = level;
	      coeff[1][i] = level - 1;
	    }
	  else
	    {
	      level = (bias - level) >> 21;
	      coeff[0][i] = -level;
	      coeff[1][i] = -level + 1;
	    }
	  coeff_count[i] = ((level) > (2) ? (2) : (level));
	  ((void) 0);
	  max |= level;
	}
      else
	{
	  coeff[0][i] = (level >> 31) | 1;
	  coeff_count[i] = 1;
	}
     } IACA_END
}
