#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VLC;

int
fn (int i, VLC vlc[4])
{
  IACA_START for (i = 0; i < 4; i++)
    {
      ff_free_vlc (&vlc[i]);
     } IACA_END
}
