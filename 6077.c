#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int16_t int16_t;

int
fn (int16_t * ref_dst, int i, BitstreamContext * bc, int mode,
    const int *const ff_gsm_apcm_bits[][4])
{
  for (i = 0; i < 4; i++)
    {
      int lag = bitstream_read (bc, 7);
      int gain_idx = bitstream_read (bc, 2);
      int offset = bitstream_read (bc, 2);
      lag = av_clip_c (lag, 40, 120);
      long_term_synth (ref_dst, lag, gain_idx);
      apcm_dequant_add (bc, ref_dst + offset, ff_gsm_apcm_bits[mode][i]);
      ref_dst += 40;
}}
