#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;

int
fn (int *log2_block_cnt, int log2_block_count_tmp, int i,
    BitstreamContext * bc)
{
  for (i = 0; i < 2; i++)
    {
      log2_block_count_tmp = bitstream_read (bc, 2);
      if (log2_block_count_tmp & 1)
	return (-0x3ebbb1b7);
      log2_block_cnt[i] = 2 - log2_block_count_tmp;
    }
}
