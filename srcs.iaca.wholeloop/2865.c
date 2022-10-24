#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int out2[12], int *buf, int *win, int *out_ptr)
{
  IACA_START for (i = 0; i < 6; i++)
    {
      *out_ptr = MULH ((1) * (out2[i]), win[i]) + buf[4 * (i + 6 * 1)];
      buf[4 * (i + 6 * 2)] = MULH ((1) * (out2[i + 6]), win[i + 6]);
      out_ptr += 32;
     } IACA_END
}
