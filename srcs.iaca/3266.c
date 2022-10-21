#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VLC;

int
fn (int i, VLC vlc[4])
{
  for (i = 0; i < 4; i++)
     { IACA_START
      ff_free_vlc (&vlc[i]);
     } IACA_END
}
