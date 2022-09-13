#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int dst_size, int i, int sz, int code_table[64], GetBitContext gb)
{
  for (i = 0, sz = 0; i < 64 && sz < dst_size; i++)
    {
      if (get_bits_left (&gb) < 4)
	return ((void *) 0);
      code_table[i] = get_sbits (&gb, 4);
      sz += ((code_table[i]) >= 0 ? (code_table[i]) : (-(code_table[i])));
}}
