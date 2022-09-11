#include <stdint.h>
#include <stdio.h>






int
fn (const double *a, double imagz, double w, int nb_a, double realz)
{
  for (int x = 0; x < nb_a; x++)
    {
      realz += cos (-x * w) * a[x];
      imagz += sin (-x * w) * a[x];
}}
