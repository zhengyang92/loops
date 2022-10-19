#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;

int
fn (int offset, int code, uint8_t * out, GetByteContext * gbc, int j, int pix,
    int step)
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
