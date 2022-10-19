#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint32_t uint32_t;

int
fn (GetByteContext * gbc, int i, uint32_t * p)
{
  for (i = 0; i < 256; i++)
    {
      uint32_t rgba = 0;
      rgba |= bytestream2_get_byte (gbc) << 16;
      rgba |= bytestream2_get_byte (gbc) << 8;
      rgba |= bytestream2_get_byte (gbc) << 0;
      rgba |= bytestream2_get_byte (gbc) << 24;
      p[i] = rgba;
    }
}
