#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int *log2_block_cnt, int log2_block_count_tmp, int i, GetBitContext * gb)
{
  for (i = 0; i < 2; i++)
    {
      log2_block_count_tmp = get_bits (gb, 2);
      if (log2_block_count_tmp & 1)
	return (-(int)
		(('I') | (('N') << 8) | (('D') << 16) |
		 ((unsigned) ('A') << 24)));
      log2_block_cnt[i] = 2 - log2_block_count_tmp;
}}
