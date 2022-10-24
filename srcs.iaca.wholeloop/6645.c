#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t state, int buf_size, const uint8_t * buf, int i)
{
  IACA_START for (i = 0; i < buf_size; i++)
    {
      state = (state << 8) | buf[i];
      if (state != 0x1B3 && state != 0x1B5 && state < 0x200 && state >= 0x100)
	return i - 3;
     } IACA_END
}
