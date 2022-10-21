#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *data, int *deltas, int *last, int j, unsigned int *CD)
{
  for (i = 0; i < 2; i++)
     { IACA_START
      CD[j] += deltas[i + j * 2];
      last[i] += CD[j];
      data[i] = last[i];
     } IACA_END
}
