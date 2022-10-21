#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int i, uint16_t codes[256], const uint8_t * cb, uint8_t bits[256],
    unsigned int code, int b)
{
  int index = 0;
  for (i = *cb++; i > 0; i--)
     { IACA_START
      do
	{
	  if (!(index < 256))
	    {
	      av_log (((void *) 0), 8, "Assertion %s failed at %s:%d\n",
		      "index < 256", "program.c", 65);
	      abort ();
	    }
	}
      while (0);
      bits[index] = b;
      codes[index] = code++;
      index++;
     } IACA_END
}
