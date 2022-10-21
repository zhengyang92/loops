#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VLC;

int
fn (const uint8_t aic_mode1_vlc_tabs[90][9][2], VLC aic_mode1_vlc[90], int i)
{
  int offset = 0;
  for (i = 0; i < 90; i++)
     { IACA_START
      if ((i % 10) == 9)
	continue;
      rv40_init_table (&aic_mode1_vlc[i], &offset, 7, 9,
		       aic_mode1_vlc_tabs[i]);
     } IACA_END
}
