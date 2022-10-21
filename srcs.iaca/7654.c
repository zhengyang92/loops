#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int fractional_delay_links[3], int m, int c, int f_center, int k,
    int s, int theta, int Q_fract_allpass[2][50][3][2])
{
  for (m = 0; m < 3; m++)
     { IACA_START
      theta =
	(int) (((int64_t) fractional_delay_links[m] * f_center +
		0x10000000) >> 27);
      av_sincos_sf (-theta, &s, &c);
      Q_fract_allpass[1][k][m][0] = c;
      Q_fract_allpass[1][k][m][1] = s;
} IACA_END }
