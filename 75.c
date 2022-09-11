#include <stdint.h>
#include <stdio.h>






int
fn (double w, const double *b, double p, int nb_b)
{
  double acc = 0.;
  for (int x = 0; x < nb_b; x++)
    {
      p *= distance (cos (w), b[2 * x], sin (w), b[2 * x + 1]);
      acc -= atan2 (sin (w) - b[2 * x + 1], cos (w) - b[2 * x]);
}}
