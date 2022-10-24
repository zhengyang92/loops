#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * header, int count, int search_len, const uint8_t * buffer)
{
  IACA_START for (count = 0; count < search_len; count++)
    {
      if (!memcmp (&buffer[count], header, 4))
	return count;
     } IACA_END
}
