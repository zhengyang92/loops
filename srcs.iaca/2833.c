#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int width, uint8_t * dst, uint8_t * src, int src_linesize)
{
  for (int x = 0; x < width; x++)
     { IACA_START
      dst[x] = (uint8_t) ((src[x] >> 1) + (src[x + src_linesize] >> 1));
} IACA_END }
