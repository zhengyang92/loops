#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int threshold1, int bias, int i, int last_non_zero, int start_i,
    int16_t * block, unsigned int threshold2, const uint8_t * scantable,
    const int *qmat, int level, int j)
{
  int max = 0;
  for (i = start_i; i <= last_non_zero; i++)
    {
      j = scantable[i];
      level = block[j] * qmat[j];
      if (((unsigned) (level + threshold1)) > threshold2)
	{
	  if (level > 0)
	    {
	      level = (bias + level) >> 22;
	      block[j] = level;
	    }
	  else
	    {
	      level = (bias - level) >> 22;
	      block[j] = -level;
	    }
	  max |= level;
	}
      else
	{
	  block[j] = 0;
	}
    }
}
