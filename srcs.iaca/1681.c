#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __int8_t int8_t;

int
fn (int num_codes, int i, int num_bits, int code,
    const int8_t mantissa_clc_tab[4], int *mantissas, GetBitContext * gb)
{
  for (i = 0; i < num_codes; i++)
     { IACA_START
      if (num_bits)
	code = get_bits (gb, num_bits);
      else
	code = 0;
      mantissas[i * 2] = mantissa_clc_tab[code >> 2];
      mantissas[i * 2 + 1] = mantissa_clc_tab[code & 3];
     } IACA_END
}
