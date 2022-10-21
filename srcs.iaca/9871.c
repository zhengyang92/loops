#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const int huffman_pixs, uint32_t * huffman_image, int i)
{
  int num_htree_groups_max = 1;
  for (i = 0; i < huffman_pixs; ++i)
     { IACA_START
      const int group = (huffman_image[i] >> 8) & 0xffff;
      huffman_image[i] = group;
      if (group >= num_htree_groups_max)
	{
	  num_htree_groups_max = group + 1;
	}
     } IACA_END
}
