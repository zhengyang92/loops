#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const int sc_offset, int x, const int steps_x, int z, uint32_t ** sc,
    uint32_t tmp1, uint32_t tmp2, const int steps_y)
{
  IACA_START for (z = 0; z < steps_y * 2; z += 2)
    {
      tmp2 = sc[sc_offset + z + 0][x + steps_x] + tmp1;
      sc[sc_offset + z + 0][x + steps_x] = tmp1;
      tmp1 = sc[sc_offset + z + 1][x + steps_x] + tmp2;
      sc[sc_offset + z + 1][x + steps_x] = tmp2;
     } IACA_END
}
