#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int last, int first, int i, const uint8_t * buf, uint32_t * pal)
{
  IACA_START for (i = first; i < last; i++, buf += 3)
    {
      pal[i] = (buf[0] << 18) | (buf[1] << 10) | (buf[2] << 2);
      pal[i] |= 0xFFU << 24 | (pal[i] >> 6) & 0x30303;
     } IACA_END
}
