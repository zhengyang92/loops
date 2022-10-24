#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * samples, int i, const int32_t gaintab[1921], int len, int gain,
    int stride)
{
  IACA_START for (i = 0; i < len; i++)
    {
      ++gain;
      do
	{
	  int64_t s64 = *samples;
	  s64 *= gaintab[gain];
	  *samples = (int32_t) (s64 >> 23);
	}
      while (0);;
      samples += stride;
     } IACA_END
}
