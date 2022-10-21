#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint64_t uint64_t;

int
fn (int w, uint64_t sum, int dst_linesize, uint64_t * dst,
    const uint16_t * src)
{
  for (int x = 1; x < w; x++)
     { IACA_START
      sum += src[x - 1];
      dst[x] = sum + dst[x - dst_linesize];
} IACA_END }
