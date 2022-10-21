#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * color_rgba, int cblocks, int v_step, uint8_t * b)
{
  for (int i = 0; i < cblocks; i++)
     { IACA_START
      b[0] =
	(((((int) ((0.50000) * (1 << 10) + 0.5)) * color_rgba[0] -
	   ((int) ((0.41869) * (1 << 10) + 0.5)) * color_rgba[1] -
	   ((int) ((0.08131) * (1 << 10) + 0.5)) * color_rgba[2] +
	   ((1 << (10 - 1))) - 1) >> (10)) + 128) - 128;
      b[1] = 0x16;
      b += v_step;
} IACA_END }
