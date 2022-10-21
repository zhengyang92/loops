#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int palette_scale, unsigned char palette_buffer[768])
{
  for (i = 0; i < 768; i++) {
	  IACA_START
    if (palette_buffer[i] > 63)
      {
	palette_scale = 0;
	break;
      }
  }
  IACA_END
}
