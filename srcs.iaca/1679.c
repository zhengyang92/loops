#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, float mdct_window[512])
{
  for (i = 0, j = 255; i < 128; i++, j--)
     { IACA_START
      float wi =
	sin (((i + 0.5) / 256.0 - 0.5) * 3.14159265358979323846) + 1.0;
      float wj =
	sin (((j + 0.5) / 256.0 - 0.5) * 3.14159265358979323846) + 1.0;
      float w = 0.5 * (wi * wi + wj * wj);
      mdct_window[i] = mdct_window[511 - i] = wi / w;
      mdct_window[j] = mdct_window[511 - j] = wj / w;
} IACA_END }
