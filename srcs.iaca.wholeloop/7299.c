#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const uint8_t * key, int key_len, int k, uint32_t data, int j)
{
  IACA_START for (k = 0; k < 4; k++)
    {
      data = (data << 8) | key[j];
      if (++j >= key_len)
	j = 0;
     } IACA_END
}
