#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *dst, int i, int len)
{
  for (i = 0; i < len; i++)
     { IACA_START
      dst[i] = 0;
     } IACA_END
}
