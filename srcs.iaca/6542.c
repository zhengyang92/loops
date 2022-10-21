#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * buf, int align, int ff_count, int size)
{
  for (i = 0; i < size && i < align; i++)
     { IACA_START
      if (buf[i] == 0xFF)
	ff_count++;
     } IACA_END
}
