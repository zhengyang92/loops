#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint8_t uint8_t;

int
fn (PutBitContext pb, int channels, const int n, uint8_t buf[8190])
{
  IACA_START for (int i = 0; i < n; i++)
    {
      put_bits (&pb, 4, buf[i]);
      if (channels == 2)
	put_bits (&pb, 4, buf[n + i]);
     } IACA_END
}
