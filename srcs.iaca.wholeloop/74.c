#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double w, int nb_a, const double *a)
{
  double z = 1.;
  double acc = 0.;
  IACA_START for (int x = 0; x < nb_a; x++)
    {
      z *= distance (cos (w), a[2 * x], sin (w), a[2 * x + 1]);
      acc += atan2 (sin (w) - a[2 * x + 1], cos (w) - a[2 * x]);
}IACA_END}
