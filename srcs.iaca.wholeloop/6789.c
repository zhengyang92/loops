#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;

int
fn (int offset, int step, int code, GetByteContext * gbc, int j,
    uint8_t * out)
{
  int pos = 0;
  IACA_START for (j = 0; j < code + 1; j++)
    {
      out[pos] = bytestream2_get_byte (gbc);
      pos += step;
      if (pos >= offset)
	{
	  pos -= offset;
	  pos++;
	}
     } IACA_END
}
