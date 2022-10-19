#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, unsigned short lengthc[30], int best)
{
  for (j = 0; best > lengthc[j + 1] - 1; ++j);
}
