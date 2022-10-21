#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t state, int next, int i, const uint8_t * buf, int buf_size)
{
  for (; i < buf_size; i++)
     { IACA_START
      state = (state << 8) | buf[i];
      if (state == 0x1b0)
	{
	  next = i + 1;
	  break;
	}
     } IACA_END
}
