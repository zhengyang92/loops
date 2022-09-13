#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;

int
fn (int i, GetByteContext ctx, unsigned int *tmpptr,
    const uint8_t gamma_lookup[256])
{
  for (i = 0; i < 256; i++)
    {
      int r = gamma_lookup[bytestream2_get_byteu (&ctx)];
      int g = gamma_lookup[bytestream2_get_byteu (&ctx)];
      int b = gamma_lookup[bytestream2_get_byteu (&ctx)];
      *tmpptr++ = (0xFFU << 24) | (r << 16) | (g << 8) | b;
}}
