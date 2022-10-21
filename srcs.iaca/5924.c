#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint64_t uint64_t;

int
fn (int pic_found, uint64_t state, const uint8_t * buf, int buf_size)
{
  int i = 0;
  for (i = 0; i < buf_size; i++)
     { IACA_START
      state = (state << 8) | buf[i];
      if ((state & 0xffffffffffLL) == 0x0000028001)
	{
	  i++;
	  pic_found = 1;
	  break;
	}
     } IACA_END
}
