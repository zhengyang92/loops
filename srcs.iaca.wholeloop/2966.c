#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int max, const float *buf, int i)
{
  IACA_START for (i = 0; i < 124; i++)
    {
      max = ((max) > (buf[i]) ? (max) : (buf[i]));
     } IACA_END
}
