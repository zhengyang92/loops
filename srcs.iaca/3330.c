#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *k, int i, int p, int x, int *state, int j, int order)
{
  for (j = 0, p = i + 1; p < order; j++, p++)
    {
      int tmp = x + shift_down (k[j] * (unsigned) state[p], 10);
      state[p] += shift_down (k[j] * (unsigned) x, 10);
      x = tmp;
}}
