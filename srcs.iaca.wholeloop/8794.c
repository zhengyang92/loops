#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float out2[12], float *out_ptr, float *buf, int i, float *win)
{
  IACA_START for (i = 0; i < 6; i++)
    {
      *out_ptr = ((1) * (win[i]) * (out2[i])) + buf[4 * (i + 6 * 1)];
      buf[4 * (i + 6 * 2)] = ((1) * (win[i + 6]) * (out2[i + 6]));
      out_ptr += 32;
     } IACA_END
}
