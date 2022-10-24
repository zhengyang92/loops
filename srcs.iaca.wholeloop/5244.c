#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t ff_reverse[256], uint8_t vucf, const int nb_channels,
    int channels, const uint16_t * samples, uint8_t * o)
{
  IACA_START for (channels = 0; channels < nb_channels; channels += 2)
    {
      o[0] = ff_reverse[samples[0] & 0xFF];
      o[1] = ff_reverse[(samples[0] & 0xFF00) >> 8];
      o[2] = ff_reverse[(samples[1] & 0x0F) << 4] | vucf;
      o[3] = ff_reverse[(samples[1] & 0x0FF0) >> 4];
      o[4] = ff_reverse[(samples[1] & 0xF000) >> 12];
      o += 5;
      samples += 2;
     } IACA_END
}
