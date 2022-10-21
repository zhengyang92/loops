#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int16_t int16_t;

int
fn (const int16_t * tab, int i, int16_t * dst,
    const uint8_t ff_gsm_requant_tab[4][8], int val, BitstreamContext * bc,
    const int *frame_bits)
{
  for (i = 0; i < 13; i++)
     { IACA_START
      val = bitstream_read (bc, frame_bits[i]);
      dst[3 * i] += tab[ff_gsm_requant_tab[frame_bits[i]][val]];
     } IACA_END
}
