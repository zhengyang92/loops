#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int max, const float *buf, int i)
{
  for (i = 0; i < 124; i++)
     { IACA_START
      max = ((max) > (buf[i]) ? (max) : (buf[i]));
     } IACA_END
}
