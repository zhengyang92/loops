#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef VLC;

int
fn (const uint8_t * xlats, VLC spec_vlc_tabs[112], int i,
    const int8_t atrac3p_spectra_cbs[112][12])
{
  int tab_offset = 0;
  for (i = 0; i < 112; i++)
    {
      if (atrac3p_spectra_cbs[i][0] >= 0)
	build_canonical_huff (atrac3p_spectra_cbs[i], &xlats, &tab_offset,
			      &spec_vlc_tabs[i]);
      else
	spec_vlc_tabs[i] = spec_vlc_tabs[-atrac3p_spectra_cbs[i][0]];
    }
}
