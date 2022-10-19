#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, uint32_t * idx_map, uint32_t * sorted, int num_colors,
    const uint32_t * palette)
{
  for (i = 0; i < num_colors; ++i)
    {
      idx_map[SearchColorNoIdx (sorted, palette[i], num_colors)] = i;
    }
}
