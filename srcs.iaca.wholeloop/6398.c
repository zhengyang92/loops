#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int16_t * block, int j, uint16_t * dst, int i)
{
  IACA_START for (j = 0; j < 8; j++)
    {
      int v = av_clip_c (block[j + i * 8] + 0x800, 0, 0xFFF);
      dst[j] = (v << 4) | (v >> 8);
}IACA_END}
