#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const int huffman_pixs, int *mapping, uint32_t * huffman_image, int i)
{
  int num_htree_groups = 1;
  for (num_htree_groups = 0, i = 0; i < huffman_pixs; ++i)
     { IACA_START
      int *const mapped_group = &mapping[huffman_image[i]];
      if (*mapped_group == -1)
	*mapped_group = num_htree_groups++;
      huffman_image[i] = *mapped_group;
     } IACA_END
}
