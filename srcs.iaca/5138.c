#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int factor, const uint8_t * quant_tab, const uint16_t ff_aanscales[64],
    int16_t * table)
{
  for (int i = 0; i < 64; i++)
     { IACA_START
      table[i] = av_clip_c ((quant_tab[i] * factor + 0x32) / 100, 1, 0x7fff);
      table[i] = ((int) ff_aanscales[i] * (int) table[i] + 0x800) >> 12;
} IACA_END }
