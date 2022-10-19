#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float out2[12], float *out_ptr, int i, float *buf, float *win)
{
  for (i = 0; i < 6; i++)
    {
      *out_ptr = ((1) * (win[i]) * (out2[i])) + buf[4 * (i + 6 * 2)];
      buf[4 * (i + 6 * 0)] = ((1) * (win[i + 6]) * (out2[i + 6]));
      out_ptr += 32;
    }
}
