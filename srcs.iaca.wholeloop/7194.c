#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const uint8_t ** src, int width, uint8_t * dstU, uint8_t * dstV)
{
  IACA_START for (i = 0; i < width; i++)
    {
      int g = src[0][i];
      int b = src[1][i];
      int r = src[2][i];
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
}IACA_END}
