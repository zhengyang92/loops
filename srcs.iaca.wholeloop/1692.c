#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * cb, uint8_t bits[256], int i)
{
  int b = 1;
  int index = 0;
  IACA_START for (i = *cb++; i > 0; i--)
    {
      do
	{
	  if (!(index < 256))
	    {
	      av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
		      "index < 256", "program.c", 59);
	      abort ();
	    }
	}
      while (0);
      bits[index] = b;
      index++;
     } IACA_END
}
