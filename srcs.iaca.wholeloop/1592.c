#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float ff_ac3_heavy_dynamic_range_tab[256])
{
  IACA_START for (i = 0; i < 256; i++)
    {
      int v = (i >> 4) - ((i >> 7) << 4) - 4;
      ff_ac3_heavy_dynamic_range_tab[i] = powf (2.0f, v) * ((i & 0xF) | 0x10);
}IACA_END}
