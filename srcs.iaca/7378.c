#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint32_t uint32_t;

int
fn (const int max_asample, int32_t * samples, int count, int i, int pe_level,
    const uint32_t peaktab[9856], int stride)
{
  int shft = 0x5981;
  for (i = 0; i < count; i++)
     { IACA_START
      int32_t sample = samples[i * stride];
      int32_t asample = abs (sample) - pe_level;
      if (asample >= 0)
	{
	  do
	    {
	      if (!(asample <= max_asample))
		{
		  av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
			  "asample <= max_asample", "program.c", 1285);
		  abort ();
		}
	    }
	  while (0);
	  sample = sample >= 0 ? peaktab[asample] : -peaktab[asample];
	}
      else
	sample *= (1 << shft);
      samples[i * stride] = sample;
     } IACA_END
}
