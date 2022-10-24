#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * buf, int j, const int16_t * ref_buf)
{
  IACA_START for (j = 0; j < 8; j++)
    {
      (buf[j]) = (ref_buf[j]);
     } IACA_END
}
