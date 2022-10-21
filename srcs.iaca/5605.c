#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, unsigned int code, char *to)
{
  for (i = 2; i >= 0; i--)
     { IACA_START
      to[i] = 0x60 + (code & 0x1f);
      code >>= 5;
     } IACA_END
}
