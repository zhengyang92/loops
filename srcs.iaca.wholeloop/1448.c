#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *dst, int i, int len)
{
  IACA_START for (i = 0; i < len; i++)
    {
      dst[i] = 0;
     } IACA_END
}
