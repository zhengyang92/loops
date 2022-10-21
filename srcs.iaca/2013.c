#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint8_t * rgb[3], int c, uint16_t * ptr_x, int rgb_channel_count)
{
  for (c = 0; c < rgb_channel_count; c++)
     { IACA_START
      *ptr_x++ = bytestream_get_le32 (&rgb[c]) >> 16;
     } IACA_END
}
