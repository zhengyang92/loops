#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double imagz, const double *a, double w, int nb_a, double realz)
{
  IACA_START for (int x = 0; x < nb_a; x++)
    {
      realz += cos (-x * w) * a[x];
      imagz += sin (-x * w) * a[x];
}IACA_END}
