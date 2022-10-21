#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint64_t uint64_t;

int
fn (int next, int i, const uint8_t * buf, uint64_t state, int buf_size)
{
  for (; i < buf_size; i++)
     { IACA_START
      state = (state << 8) | buf[i];
      if (state == 0x01LL)
	{
	  next = i + 1;
	  break;
	}
     } IACA_END
}
