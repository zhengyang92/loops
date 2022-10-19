#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*filter)[8][2], int bands, int n, int q, const float *proto)
{
  for (n = 0; n < 7; n++)
    {
      double theta = 2 * 3.14159265358979323846 * (q + 0.5) * (n - 6) / bands;
      filter[q][n][0] = proto[n] * cos (theta);
      filter[q][n][1] = proto[n] * -sin (theta);
}}
