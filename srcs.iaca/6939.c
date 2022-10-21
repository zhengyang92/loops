#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;
typedef struct HuffEntry
{
  uint16_t sym;
  uint8_t len;
  uint32_t code;
} HuffEntry;

int
fn (int last, int i, uint32_t codes[1024], uint8_t bits[1024], uint32_t code,
    uint16_t syms[1024], HuffEntry he[1024])
{
  for (i = last; i >= 0; i--)
     { IACA_START
      codes[i] = code >> (32 - he[i].len);
      bits[i] = he[i].len;
      syms[i] = he[i].sym;
      code += 0x80000000u >> (he[i].len - 1);
     } IACA_END
}
