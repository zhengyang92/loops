#include <stdint.h>
#include <stdio.h>






int
fn (double theta, float Q_fract_allpass[2][50][3][2],
    const float fractional_delay_links[3], int m, double f_center, int k)
{
  for (m = 0; m < 3; m++)
    {
      theta = -3.14159265358979323846 * fractional_delay_links[m] * f_center;
      Q_fract_allpass[1][k][m][0] = cos (theta);
      Q_fract_allpass[1][k][m][1] = sin (theta);
    }
}