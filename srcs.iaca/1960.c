#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *out_palette, int *out_alpha, int selected[4], int i)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      out_palette[i] = selected[i] ? (selected[i] - 1) & 0xF : 0;
      out_alpha[i] = !selected[i] ? 0 : selected[i] < 17 ? 0x80 : 0xFF;
     } IACA_END
}
