#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef box_label;

int
fn (box_label * b, int n, int i)
{
  for (i = 0; i < n; ++i)
    {
      box_label swap = b[i];
      int index = rand () % n;
      b[i] = b[index];
      b[index] = swap;
}}
