#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *dst, int len, int i)
{
  IACA_START for (i = 0; i < len; i++)
    {
      dst[i] = 0;
     } IACA_END
}
