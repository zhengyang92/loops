#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int ff_count, int i, uint8_t * buf, int size)
{
  IACA_START for (; i < size; i++)
    {
      if (buf[i] == 0xFF)
	ff_count++;
     } IACA_END
}
