#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t ff_reverse[256], int n, const short *samples,
    unsigned char *dst)
{
  IACA_START for (; n > 0; n--)
    {
      uint32_t tmp =
	ff_reverse[(*samples >> 8) & 0xff] +
	(ff_reverse[*samples & 0xff] << 8);
      tmp <<= 4;
      bytestream_put_be24 (&dst, tmp);
      samples++;
     } IACA_END
}
