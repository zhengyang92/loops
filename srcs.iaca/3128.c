#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint16_t uint16_t;

int
fn (int offset, uint16_t * out, int code, GetByteContext * gbc, int j)
{
  int pos = 0;
  for (j = 0; j < code + 1; j++)
    {
      if (pos < offset)
	{
	  out[pos++] = bytestream2_get_be16 (gbc);
	}
      else
	{
	  bytestream2_skip (gbc, 2);
	}
    }
}
