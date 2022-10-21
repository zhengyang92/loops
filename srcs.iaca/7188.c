#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, uint8_t * dstU, const uint8_t * src1, uint8_t * dstV)
{
  for (i = 0; i < width; i++)
     { IACA_START
      int b = src1[3 * i + 0];
      int g = src1[3 * i + 1];
      int r = src1[3 * i + 2];
      dstU[i] =
	((-(int) (0.169 * 224 / 255 * (1 << 15) + 0.5)) * r +
	 (-(int) (0.331 * 224 / 255 * (1 << 15) + 0.5)) * g +
	 ((int) (0.500 * 224 / 255 * (1 << 15) + 0.5)) * b +
	 (257 << (15 - 1))) >> 15;
      dstV[i] =
	(((int) (0.500 * 224 / 255 * (1 << 15) + 0.5)) * r +
	 (-(int) (0.419 * 224 / 255 * (1 << 15) + 0.5)) * g +
	 (-(int) (0.081 * 224 / 255 * (1 << 15) + 0.5)) * b +
	 (257 << (15 - 1))) >> 15;
} IACA_END }
