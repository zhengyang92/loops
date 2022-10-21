#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * dst, unsigned int dst_width, int j, uint16_t * last_line)
{
  for (j = 0; j < dst_width; ++j)
     { IACA_START
      dst[j] = last_line[j];
     } IACA_END
}
