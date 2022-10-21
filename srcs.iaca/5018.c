#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int16_t * block, int j, uint16_t * dst, int i)
{
  for (j = 0; j < 8; j++)
     { IACA_START
      int v = av_clip_uintp2_c (block[j + i * 8] + 0x800, 12);
      dst[j] = (v << 4) | (v >> 8);
} IACA_END }
