#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *last, int i, unsigned int *Yo, int *Y)
{
  for (i = 0; i < 4; i++)
    {
      Y[i] = Yo[i];
      last[i] = Yo[i];
    }
}
