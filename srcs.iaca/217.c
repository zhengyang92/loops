#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, const int in_channels, int wr, float *buffer[64], int l)
{
  for (l = 0; l < in_channels; l++)
     { IACA_START
      *(buffer[l] + wr) = src[l];
     } IACA_END
}
