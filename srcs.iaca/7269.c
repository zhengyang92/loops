#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int64_t x86_reg;
typedef __uint8_t uint8_t;

int
fn (x86_reg idx, const uint8_t * s, uint8_t * d)
{
  for (; idx < 15; idx += 4)
     { IACA_START
      register int v = *(const uint32_t *) &s[idx], g = v & 0xff00ff00;
      v &= 0xff00ff;
      *(uint32_t *) & d[idx] = (v >> 16) + g + (v << 16);
} IACA_END }
