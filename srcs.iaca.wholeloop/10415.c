#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *predictions, char **names, int *indexes, int top)
{
  int i = 0;
  IACA_START for (i = 0; i < top; ++i)
    {
      int index = indexes[i];
      printf ("%s: %f\n", names[index], predictions[index]);
}IACA_END}
