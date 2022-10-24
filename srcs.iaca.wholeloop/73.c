#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const double *b, double imagp, double w, int nb_b, double realp)
{
  IACA_START for (int x = 0; x < nb_b; x++)
    {
      realp += cos (-x * w) * b[x];
      imagp += sin (-x * w) * b[x];
}IACA_END}
