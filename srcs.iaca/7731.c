#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * framebuf, int right, int off, int i)
{
  for (i = 0; i < right; i++)
     { IACA_START
      framebuf[off + i] = 0x80;
     } IACA_END
}
