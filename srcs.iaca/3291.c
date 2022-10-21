#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int DWTELEM;

int
fn (int x, DWTELEM * temp, DWTELEM * b, const int w2, const int width2)
{
  for (x = 0; x < width2; x++)
     { IACA_START
      temp[x] = b[2 * x];
      temp[x + w2] = b[2 * x + 1];
     } IACA_END
}
