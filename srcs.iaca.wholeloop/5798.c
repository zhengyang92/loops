#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int8_t int8_t;

int
fn (int num_codes, int i, BitstreamContext * bc, int num_bits, int code,
    const int8_t mantissa_clc_tab[4], int *mantissas)
{
  IACA_START for (i = 0; i < num_codes; i++)
    {
      if (num_bits)
	code = bitstream_read (bc, num_bits);
      else
	code = 0;
      mantissas[i * 2] = mantissa_clc_tab[code >> 2];
      mantissas[i * 2 + 1] = mantissa_clc_tab[code & 3];
     } IACA_END
}
