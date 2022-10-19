#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VLC;

int
fn (const uint8_t ptype_vlc_tabs[7][8][2], VLC ptype_vlc[7], int i)
{
  int offset = 0;
  for (i = 0; i < 7; i++)
    {
      rv40_init_table (&ptype_vlc[i], &offset, 7, 8, ptype_vlc_tabs[i]);
    }
}
