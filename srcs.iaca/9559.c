#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;

int
fn (int dst_size, int i, int sz, BitstreamContext bc, int code_table[64])
{
  for (i = 0, sz = 0; i < 64 && sz < dst_size; i++)
     { IACA_START
      if (bitstream_bits_left (&bc) < 4)
	return ((void *) 0);
      code_table[i] = bitstream_read_signed (&bc, 4);
      sz += ((code_table[i]) >= 0 ? (code_table[i]) : (-(code_table[i])));
} IACA_END }
