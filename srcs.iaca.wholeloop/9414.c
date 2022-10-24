#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *buf, int i, int *out_ptr)
{
  IACA_START for (i = 0; i < 6; i++)
    {
      *out_ptr = buf[4 * i];
      out_ptr += 32;
     } IACA_END
}
