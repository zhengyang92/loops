#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef long unsigned int size_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * data, int bits[2][8], unsigned int consumed, int ch,
    int bit, uint32_t audio_sample, size_t len, int sb)
{
  for (bit = 0; bit < bits[ch][sb]; bit++)
     { IACA_START
      if (consumed > len * 8)
	return -1;
      if ((data[consumed >> 3] >> (7 - (consumed & 0x7))) & 0x01)
	audio_sample |= 1 << (bits[ch][sb] - bit - 1);
      consumed++;
     } IACA_END
}
