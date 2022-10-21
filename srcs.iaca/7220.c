#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ydst, const int chromWidth, int i, const uint8_t * src)
{
  for (i = 0; i < chromWidth; i++)
     { IACA_START
      unsigned int b = src[6 * i + 0];
      unsigned int g = src[6 * i + 1];
      unsigned int r = src[6 * i + 2];
      unsigned int Y =
	((((int) (0.257 * (1 << 8) + 0.5)) * r +
	  ((int) (0.504 * (1 << 8) + 0.5)) * g +
	  ((int) (0.098 * (1 << 8) + 0.5)) * b) >> 8) + 16;
      ydst[2 * i] = Y;
      b = src[6 * i + 3];
      g = src[6 * i + 4];
      r = src[6 * i + 5];
      Y =
	((((int) (0.257 * (1 << 8) + 0.5)) * r +
	  ((int) (0.504 * (1 << 8) + 0.5)) * g +
	  ((int) (0.098 * (1 << 8) + 0.5)) * b) >> 8) + 16;
      ydst[2 * i + 1] = Y;
} IACA_END }
