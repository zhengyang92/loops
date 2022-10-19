#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int num_codes, int i, int num_bits, int code, int *mantissas,
    GetBitContext * gb)
{
  for (i = 0; i < num_codes; i++)
    {
      if (num_bits)
	code = get_sbits (gb, num_bits);
      else
	code = 0;
      mantissas[i] = code;
    }
}
