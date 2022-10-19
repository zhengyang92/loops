#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *predictions, int indexes[10], char **names)
{
  int i = 0;
  for (i = 0; i < 10; ++i)
    {
      int index = indexes[i];
      printf ("%.1f%%: %s\n", predictions[index] * 100, names[index]);
}}
