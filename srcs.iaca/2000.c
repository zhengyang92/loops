#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * fixed_index, float *cod, int offset, int i, int pos1,
    int pos2)
{
  for (i = 0; i < 3; i++)
     { IACA_START
      pos1 = ((fixed_index[i] & 0x7f) / 11) * 5 + ((i + offset) % 5);
      pos2 = ((fixed_index[i] & 0x7f) % 11) * 5 + ((i + offset) % 5);
      cod[pos1] = (fixed_index[i] & 0x80) ? -1.0 : 1.0;
      if (pos2 < pos1)
	cod[pos2] = -cod[pos1];
      else
	cod[pos2] += cod[pos1];
     } IACA_END
}
