#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint64_t uint64_t;

int
fn (int stats_size, int i, uint16_t * map, const uint64_t * stats,
    uint8_t * dst, int skip0)
{
  int size = 0;
  for (i = 0; i < stats_size; i++)
    {
      dst[i] = 255;
      if (stats[i] || !skip0)
	map[size++] = i;
    }
}
