#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef EncBlockInfo;

int
fn (int size[5], EncBlockInfo * b, int i, int j, int qlevels[5])
{
  for (j = 0; j < 8; j++, b++)
    {
      size[i] += dv100_actual_quantize (b, qlevels[i]);
    }
}
