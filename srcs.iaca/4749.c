#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int difference_selector, const uint8_t offset_table[4],
    unsigned int y[4], int i, int y_avg, const int8_t sign_table[64][4],
    unsigned int sign_selector)
{
  for (i = 0; i < 4; i++)
    {
      y[i] =
	av_clip_c (y_avg +
		   offset_table[difference_selector] *
		   sign_table[sign_selector][i], 0, 63);
    }
}
