#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *out_ptr, int *buf, int i)
{
  for (i = 0; i < 6; i++)
     { IACA_START
      *out_ptr = buf[4 * i];
      out_ptr += 32;
     } IACA_END
}
