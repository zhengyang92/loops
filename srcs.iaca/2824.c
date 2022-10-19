#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const uint8_t * buf, int crc, int num_bytes, unsigned int bit_size)
{
  for (i = 0; i < ((bit_size + 2) & 7); i++)
    {
      crc <<= 1;
      if (crc & 0x100)
	crc ^= 0x11D;
      crc ^= (buf[num_bytes] >> (7 - i)) & 1;
    }
}
