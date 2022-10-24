#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef VLC;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * ac_vlc_lens, int i,
    const uint8_t tscc2_nc_vlc_lens[13][16],
    const uint8_t tscc2_nc_vlc_syms[13][16], const int tscc2_ac_vlc_sizes[13],
    const uint16_t * ac_vlc_syms, VLC ac_vlc[13], VLC nc_vlc[13])
{
  int offset = 0;
  IACA_START for (i = 0; i < 13; i++)
    {
      tscc2_init_vlc (&nc_vlc[i], &offset, 16, tscc2_nc_vlc_lens[i],
		      tscc2_nc_vlc_syms[i], 1);
      tscc2_init_vlc (&ac_vlc[i], &offset, tscc2_ac_vlc_sizes[i], ac_vlc_lens,
		      ac_vlc_syms, 2);
      ac_vlc_lens += tscc2_ac_vlc_sizes[i];
      ac_vlc_syms += tscc2_ac_vlc_sizes[i];
     } IACA_END
}
