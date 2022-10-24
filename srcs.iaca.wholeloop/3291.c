#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int DWTELEM;

int
fn (int x, DWTELEM * temp, DWTELEM * b, const int w2, const int width2)
{
  IACA_START for (x = 0; x < width2; x++)
    {
      temp[x] = b[2 * x];
      temp[x + w2] = b[2 * x + 1];
     } IACA_END
}
