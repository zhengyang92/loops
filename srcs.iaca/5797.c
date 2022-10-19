#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;

int
fn (int num_codes, int i, BitstreamContext * bc, int num_bits, int code,
    int *mantissas)
{
  for (i = 0; i < num_codes; i++)
    {
      if (num_bits)
	code = bitstream_read_signed (bc, num_bits);
      else
	code = 0;
      mantissas[i] = code;
    }
}
