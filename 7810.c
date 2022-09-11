#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t ** bytestream, const uint32_t * global_palette)
{
  for (int i = 0; i < 256; i++)
    {
      const uint32_t v = global_palette[i] & 0xffffff;
      bytestream_put_be24 (bytestream, v);
}}
