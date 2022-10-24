#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;
typedef long unsigned int size_t;

int
fn (const uint8_t * data, unsigned int consumed, int bits[2][8], int ch,
    int bit, uint32_t audio_sample, size_t len, int sb)
{
  IACA_START for (bit = 0; bit < bits[ch][sb]; bit++)
    {
      if (consumed > len * 8)
	return -1;
      if ((data[consumed >> 3] >> (7 - (consumed & 0x7))) & 0x01)
	audio_sample |= 1 << (bits[ch][sb] - bit - 1);
      consumed++;
     } IACA_END
}
