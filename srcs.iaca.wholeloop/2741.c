#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (const uint8_t series[7], int i, GetBitContext * gb)
{
  int bit = 0;
  int bits = 0;
  int prevbit = 0;
  IACA_START for (i = 0; i < 7; i++)
    {
      if (prevbit && bit)
	break;
      prevbit = bit;
      bit = get_bits1 (gb);
      if (bit && !prevbit)
	bits += series[i];
     } IACA_END
}
