#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (uint8_t * bap, int m, int16_t * psd, int band_end,
    const uint8_t * bap_tab, int bin)
{
  for (; bin < band_end; bin++)
     { IACA_START
      int address = av_clip_uintp2_c ((psd[bin] - m) >> 5, 6);
      bap[bin] = bap_tab[address];
} IACA_END }
