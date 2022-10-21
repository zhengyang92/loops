#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VLC;

int
fn (VLC btype_vlc[6], int i, const uint8_t btype_vlc_tabs[6][7][2])
{
  int offset = 0;
  for (i = 0; i < 6; i++)
     { IACA_START
      rv40_init_table (&btype_vlc[i], &offset, 6, 7, btype_vlc_tabs[i]);
     } IACA_END
}
