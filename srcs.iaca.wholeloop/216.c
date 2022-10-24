#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int in_channels, const int buffer_length, float *buffer[64], int l,
    float *ringbuffer)
{
  IACA_START for (l = 0; l < in_channels; l++)
    {
      buffer[l] = ringbuffer + l * buffer_length;
     } IACA_END
}
