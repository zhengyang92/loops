#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint16_t uint16_t;

int
fn (uint32_t speedhq_lum_dc_uni[512],
    const uint16_t mpeg12_vlc_dc_chroma_code_reversed[12],
    const uint16_t mpeg12_vlc_dc_lum_code_reversed[12],
    const unsigned char ff_mpeg12_vlc_dc_chroma_bits[12],
    uint32_t speedhq_chr_dc_uni[512],
    const unsigned char ff_mpeg12_vlc_dc_lum_bits[12])
{
  for (int i = -255; i < 256; i++)
     { IACA_START
      int adiff, index;
      int bits, code;
      int diff = i;
      adiff = ((diff) >= 0 ? (diff) : (-(diff)));
      if (diff < 0)
	diff--;
      index = (31 - __builtin_clz ((2 * adiff) | 1));
      bits = ff_mpeg12_vlc_dc_lum_bits[index] + index;
      code =
	mpeg12_vlc_dc_lum_code_reversed[index] +
	(av_mod_uintp2_c (diff, index) << ff_mpeg12_vlc_dc_lum_bits[index]);
      speedhq_lum_dc_uni[i + 255] = bits + (code << 8);
      bits = ff_mpeg12_vlc_dc_chroma_bits[index] + index;
      code =
	mpeg12_vlc_dc_chroma_code_reversed[index] +
	(av_mod_uintp2_c (diff, index) <<
	 ff_mpeg12_vlc_dc_chroma_bits[index]);
      speedhq_chr_dc_uni[i + 255] = bits + (code << 8);
     } IACA_END
}
