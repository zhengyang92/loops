#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *ptr, int column_step, float boundaryscale)
{
  IACA_START for (int k = 0; k < column_step; k++)
    {
      ptr[k] *= boundaryscale;
}IACA_END}
