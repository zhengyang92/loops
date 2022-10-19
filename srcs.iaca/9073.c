#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int m, uint8_t * bap, int band_end, int16_t * psd,
    const uint8_t * bap_tab, int bin)
{
  for (; bin < band_end; bin++)
    {
      int address = av_clip_uintp2_c ((psd[bin] - m) >> 5, 6);
      bap[bin] = bap_tab[address];
}}
