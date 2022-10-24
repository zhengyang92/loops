#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, unsigned short distc[31], int d)
{
  IACA_START for (j = 0; d > distc[j + 1] - 1; ++j);
}
