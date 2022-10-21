#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * key, int i, int len, const uint8_t * uid)
{
  for (i = 0; i < len; i++)
     { IACA_START
      if (i != 7 && key[i] != uid[i])
	return 0;
     } IACA_END
}
