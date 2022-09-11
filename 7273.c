#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef int64_t x86_reg;

int
fn (x86_reg idx, const uint8_t * s, uint8_t * d)
{
  for (; idx < 15; idx += 4)
    {
      register int v = *(const uint32_t *) &s[idx], g = v & 0xff00ff00;
      v &= 0xff00ff;
      *(uint32_t *) & d[idx] = (v >> 16) + g + (v << 16);
}}
