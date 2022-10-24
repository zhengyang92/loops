#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * uni_ac_vlc_len, int level, const uint8_t * huff_size_ac)
{
  int i = 0;
  IACA_START for (int run = 0; run < 64; run++)
    {
      int len, code, nbits;
      int alevel = ((level) >= 0 ? (level) : (-(level)));
      len = (run >> 4) * huff_size_ac[0xf0];
      nbits = (31 - __builtin_clz ((alevel) | 1)) + 1;
      code = ((15 & run) << 4) | nbits;
      len += huff_size_ac[code] + nbits;
      uni_ac_vlc_len[((run) * 128 + (i))] = len;
}IACA_END}
