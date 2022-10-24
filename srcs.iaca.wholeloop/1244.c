#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int err, char buf[1024], int i)
{
  IACA_START for (i = 0; i < 3; ++i)
    {
      if (buf[i] < '0' || buf[i] > '9')
	{
	  err = 0;
	  break;
	}
      err *= 10;
      err += buf[i] - '0';
     } IACA_END
}
