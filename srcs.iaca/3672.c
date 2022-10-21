#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int *pitch, int offset, int bits, const int16_t start_offset[94])
{
  for (offset = start_offset[bits]; offset < 0; offset += pitch[0]) { IACA_START} ; IACA_END
}
