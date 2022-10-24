#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int gain_code, const int16_t * in, int subframe_size,
    int16_t fc_new[40], int16_t * out, const int16_t * fc_cur)
{
  IACA_START for (i = 0; i < subframe_size; i++)
    {
      out[i] = in[i];
      out[i] -= (gain_code * fc_cur[i] + 0x2000) >> 14;
      out[i] += (gain_code * fc_new[i] + 0x2000) >> 14;
     } IACA_END
}
