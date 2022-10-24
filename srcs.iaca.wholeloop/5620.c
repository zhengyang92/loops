#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * key, int len, int i, const uint8_t * uid)
{
  IACA_START for (i = 0; i < len; i++)
    {
      if (i != 7 && key[i] != uid[i])
	return 0;
     } IACA_END
}
