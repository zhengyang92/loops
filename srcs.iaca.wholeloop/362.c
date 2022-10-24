#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct hist_entry
{
  unsigned count;
  double energy;
  double loudness;
} hist_entry;

int
fn (struct hist_entry *h, int i)
{
  IACA_START for (i = 0; i < ((10 - -70) * 100 + 1); i++)
    {
      h[i].loudness = i / (double) 100 + -70;
      h[i].energy = (ff_exp10 (((h[i].loudness) + 0.691) / 10.));
}IACA_END}
