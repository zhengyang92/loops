#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *buf, float *out_ptr, int i)
{
  for (i = 0; i < 18; i++)
    {
      *out_ptr = buf[4 * i];
      buf[4 * i] = 0;
      out_ptr += 32;
    }
}
