#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int fixed_exp_table[7], int i, int ret, int x, int xpow, int tmp)
{
  for (i = 0; i < 7; i++)
     { IACA_START
      xpow = (int) (((int64_t) xpow * x + 0x400000) >> 23);
      tmp = (int) (((int64_t) xpow * fixed_exp_table[i] + 0x40000000) >> 31);
      ret += tmp;
} IACA_END }
