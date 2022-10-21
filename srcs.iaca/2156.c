#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __int16_t int16_t;

int
fn (int16_t * ref_dst, int i, int mode,
    const int *const ff_gsm_apcm_bits[][4], GetBitContext * gb)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      int lag = get_bits (gb, 7);
      int gain_idx = get_bits (gb, 2);
      int offset = get_bits (gb, 2);
      lag = av_clip_c (lag, 40, 120);
      long_term_synth (ref_dst, lag, gain_idx);
      apcm_dequant_add (gb, ref_dst + offset, ff_gsm_apcm_bits[mode][i]);
      ref_dst += 40;
} IACA_END }
