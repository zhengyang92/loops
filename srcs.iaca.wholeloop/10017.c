#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint16_t uint16_t;

int
fn (const uint32_t * const argb, int i, uint16_t * counts)
{
  IACA_START for (; i >= 0; --i, --counts)
    {
      if (argb[i] == argb[i + 1])
	{
	  counts[0] = counts[1] + (counts[1] != ((1 << 12) - 1));
	}
      else
	{
	  counts[0] = 1;
	}
     } IACA_END
}
