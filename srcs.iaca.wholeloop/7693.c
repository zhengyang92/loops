#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VLC;
typedef __uint8_t uint8_t;

int
fn (VLC wl_vlc_tabs[4], const uint8_t atrac3p_wl_cbs[4][12],
    VLC ct_vlc_tabs[4], const uint8_t atrac3p_ct_cbs[4][12],
    const uint8_t * xlats)
{
  int tab_offset = 0;
  IACA_START for (int i = 0; i < 4; i++)
    {
      build_canonical_huff (atrac3p_wl_cbs[i], &xlats, &tab_offset,
			    &wl_vlc_tabs[i]);
      build_canonical_huff (atrac3p_ct_cbs[i], &xlats, &tab_offset,
			    &ct_vlc_tabs[i]);
}IACA_END}
