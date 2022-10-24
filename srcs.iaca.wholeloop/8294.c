#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int key_len, const uint8_t * key, int k, uint32_t data, int j)
{
  IACA_START for (k = 0; k < 4; k++)
    {
      data = (data << 8) | key[j];
      if (++j >= key_len)
	j = 0;
     } IACA_END
}
