#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, const int in_channels, int wr, float *buffer[64], int l)
{
  IACA_START for (l = 0; l < in_channels; l++)
    {
      *(buffer[l] + wr) = src[l];
     } IACA_END
}
