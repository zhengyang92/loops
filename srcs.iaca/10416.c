#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *predictions, char **names, int *indexes, int top)
{
  int i = 0;
  for (i = 0; i < top; ++i)
     { IACA_START
      int index = indexes[i];
      printf ("%5.2f%%: %s\n", predictions[index] * 100, names[index]);
} IACA_END }
