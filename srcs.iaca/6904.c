#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int16_t int16_t;

int
fn (int16_t predictors[256], int i, int filter_order, BitstreamContext * bc,
    int code_size_base, int code_size, int size)
{
  for (i = 4; i < filter_order; i++)
    {
      if (!(i & 3))
	code_size = code_size_base - bitstream_read (bc, 2);
      predictors[i] = bitstream_read_signed (bc, code_size) << (10 - size);
    }
}
