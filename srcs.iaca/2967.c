#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *buf, int i, short sbuf[128], int sum, short shift)
{
  for (i = 0; i < 124; i++)
     { IACA_START
      sbuf[i] = signed_shift (buf[i], shift);
      sbuf[i] = (3 * sbuf[i]) >> 2;
      sum += sbuf[i];
     } IACA_END
}
