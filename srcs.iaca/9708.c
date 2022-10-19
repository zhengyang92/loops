#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * udst, int i, const int chromWidth, uint8_t * ydst,
    uint8_t * vdst, const uint8_t * src)
{
  for (i = 0; i < chromWidth; i++)
    {
      unsigned int b = src[6 * i + 0];
      unsigned int g = src[6 * i + 1];
      unsigned int r = src[6 * i + 2];
      unsigned int Y =
	((((int) (0.257 * (1 << 8) + 0.5)) * r +
	  ((int) (0.504 * (1 << 8) + 0.5)) * g +
	  ((int) (0.098 * (1 << 8) + 0.5)) * b) >> 8) + 16;
      unsigned int V =
	((((int) (0.439 * (1 << 8) + 0.5)) * r +
	  ((int) (-0.368 * (1 << 8) + 0.5)) * g +
	  ((int) (-0.071 * (1 << 8) + 0.5)) * b) >> 8) + 128;
      unsigned int U =
	((((int) (-0.148 * (1 << 8) + 0.5)) * r +
	  ((int) (-0.291 * (1 << 8) + 0.5)) * g +
	  ((int) (0.439 * (1 << 8) + 0.5)) * b) >> 8) + 128;
      udst[i] = U;
      vdst[i] = V;
      ydst[2 * i] = Y;
      b = src[6 * i + 3];
      g = src[6 * i + 4];
      r = src[6 * i + 5];
      Y =
	((((int) (0.257 * (1 << 8) + 0.5)) * r +
	  ((int) (0.504 * (1 << 8) + 0.5)) * g +
	  ((int) (0.098 * (1 << 8) + 0.5)) * b) >> 8) + 16;
      ydst[2 * i + 1] = Y;
}}
