#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;

int
fn (int offset, int code, uint8_t * out, GetByteContext * gbc, int j,
    int step)
{
  int pos = 0;
  for (j = 0; j < code + 1; j++)
    {
      out[pos] = bytestream2_get_byte (gbc);
      pos += step;
      if (pos >= offset)
	{
	  pos -= offset;
	  pos++;
	}
    }
}
