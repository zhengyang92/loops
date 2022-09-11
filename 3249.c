#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint32_t uint32_t;

int
fn (GetBitContext gbit, uint32_t * pal)
{
  int RGBIndex = 0;
  for (int index = 0; index < 16; index++)
    {
      unsigned color = get_bits1 (&gbit) << RGBIndex;
      pal[15 - index] |= color << (5 + 8);
}}
