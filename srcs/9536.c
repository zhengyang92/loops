#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t ff_reverse[256], int buf_size, const uint8_t * buf,
    uint32_t * o)
{
  for (; buf_size > 5; buf_size -= 6)
    {
      *o++ =
	(ff_reverse[buf[2] & 0xf0] << 28) | (ff_reverse[buf[1]] << 20) |
	(ff_reverse[buf[0]] << 12);
      *o++ =
	(ff_reverse[buf[5] & 0xf0] << 28) | (ff_reverse[buf[4]] << 20) |
	(ff_reverse[buf[3]] << 12);
      buf += 6;
    }
}
