#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const new_data, const int final_num_colors, int i)
{
  for (; i < 4 * final_num_colors; ++i)
     { IACA_START
      new_data[i] = 0;
     } IACA_END
}
