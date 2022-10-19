#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int num_colors, uint8_t * const new_data, uint8_t * const data, int i)
{
  for (i = 4; i < 4 * num_colors; ++i)
    {
      new_data[i] = (data[i] + new_data[i - 4]) & 0xff;
    }
}
