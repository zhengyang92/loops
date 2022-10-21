#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint16_t * color, uint8_t dithered_color[3])
{
  for (int channel = 0; channel < 3; channel++)
     { IACA_START
      dithered_color[channel] = (((color[0]) >> ((channel) * 5) & 0x1F) * 8);
} IACA_END }
