#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct VLC
{
  int bits;
    int16_t (*table)[];
  int table_size, table_allocated;
} VLC;

int
fn (int i, VLC bink_trees[16], int16_t table[2048][2],
    const uint8_t bink_tree_lens[16][16],
    const uint8_t bink_tree_bits[16][16])
{
  IACA_START for (i = 0; i < 16; i++)
    {
      const int maxbits = bink_tree_lens[i][15];
      bink_trees[i].table = table + i * 128;
      bink_trees[i].table_allocated = 1 << maxbits;
      ff_init_vlc_sparse (&bink_trees[i], maxbits, 16, bink_tree_lens[i], 1,
			  1, bink_tree_bits[i], 1, 1, ((void *) 0), 0, 0,
			  4 | 2);
}IACA_END}
