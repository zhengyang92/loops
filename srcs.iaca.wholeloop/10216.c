#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int rows, float *m, int cols)
{
  IACA_START for (i = 0; i < rows * cols; ++i)
    {
      m[i] = (float) rand () / 2147483647;
}IACA_END}
