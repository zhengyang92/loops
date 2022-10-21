#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int pic_found, int buf_size, const uint8_t * buf, uint32_t state)
{
  int cur = 0;
  for (; cur < buf_size; ++cur)
     { IACA_START
      state = (state << 8) | buf[cur];
      if (((buf[cur]) == 0xB0 || (buf[cur]) == 0xB1 || (buf[cur]) == 0xB2
	   || ((buf[cur]) == 0xB3 || (buf[cur]) == 0xB6)))
	{
	  cur++;
	  pic_found = 1;
	  break;
	}
     } IACA_END
}
