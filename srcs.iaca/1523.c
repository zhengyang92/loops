#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int64_t f_center, const int fractional_delay_links[3], int m, int c,
    int k, int s, int theta, int Q_fract_allpass[2][50][3][2])
{
  for (m = 0; m < 3; m++)
    {
      theta =
	(int) (((int64_t) fractional_delay_links[m] * f_center + 8) >> 4);
      av_sincos_sf (-theta, &s, &c);
      Q_fract_allpass[0][k][m][0] = c;
      Q_fract_allpass[0][k][m][1] = s;
}}
