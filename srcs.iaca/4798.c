#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (unsigned int i, uint8_t ** bytestream, uint32_t shrunk_palette[256],
    unsigned int pow2_count)
{
  for (i = 0; i < 1 << (pow2_count + 1); i++)
    {
      const uint32_t v = shrunk_palette[i];
      bytestream_put_be24 (bytestream, v);
}}
