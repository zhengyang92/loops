#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int16_t int16_t;

int
fn (int i, int filter_order, int16_t (*filter), BitstreamContext * bc,
    int code_size)
{
  for (i = 0; i < filter_order; i++)
     { IACA_START
      if (!(i & 3))
	code_size = 14 - bitstream_read (bc, 3);
      filter[i] = bitstream_read_signed (bc, code_size);
     } IACA_END
}
