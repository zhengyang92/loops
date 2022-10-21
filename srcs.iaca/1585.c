#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int buf_size, const uint8_t * buf, int i)
{
  for (i = 1; i < buf_size; i += 2)
     { IACA_START
      if (buf[i] == 0x77 || buf[i] == 0x0B)
	{
	  if ((buf[i] ^ buf[i - 1]) == (0x77 ^ 0x0B))
	    {
	      i--;
	      break;
	    }
	  else if ((buf[i] ^ buf[i + 1]) == (0x77 ^ 0x0B))
	    {
	      break;
	    }
	}
     } IACA_END
}
