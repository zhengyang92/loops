#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;

int
fn (int offset, int step, int code, GetByteContext * gbc, int j, int pix,
    uint8_t * out)
{
  int pos = 0;
  for (j = 0; j < code + 1; j++)
    {
      pix = bytestream2_get_byte (gbc);
      if (pos < offset)
	out[pos] = pix;
      pos += step;
      if (pos >= offset && step > 1)
	{
	  pos -= offset;
	  pos++;
	}
    }
}
