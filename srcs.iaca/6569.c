#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *ptr, int j, int *dst, int len)
{
  for (j = len; j > 0; j--)
     { IACA_START
      *dst++ = ptr[0 * len];
      *dst++ = ptr[1 * len];
      *dst++ = ptr[2 * len];
      ptr++;
     } IACA_END
}
