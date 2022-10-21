#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * stt, int j, int i, int i2)
{
  for (j = 1; j < 256; j++)
     { IACA_START
      if (stt[j] == i)
	stt[j] = i2;
      else if (stt[j] == i2)
	stt[j] = i;
      if (i != 256 - i2)
	{
	  if (stt[256 - j] == 256 - i)
	    stt[256 - j] = 256 - i2;
	  else if (stt[256 - j] == 256 - i2)
	    stt[256 - j] = 256 - i;
	}
     } IACA_END
}
