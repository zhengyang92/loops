#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint16_t uint16_t;

int
fn (uint32_t * const histogram_argb, uint32_t i,
    uint16_t * const histogram_symbols, const uint32_t histogram_image_xysize)
{
  int max_index = 0;
  IACA_START for (i = 0; i < histogram_image_xysize; ++i)
    {
      const int symbol_index = histogram_symbols[i] & 0xffff;
      histogram_argb[i] = (symbol_index << 8);
      if (symbol_index >= max_index)
	{
	  max_index = symbol_index + 1;
	}
     } IACA_END
}
