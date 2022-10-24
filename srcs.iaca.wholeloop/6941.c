#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;
typedef struct HuffEntry
{
  uint16_t sym;
  uint8_t len;
  uint32_t code;
} HuffEntry;

int
fn (int last, int i, uint8_t syms[256], uint32_t code, HuffEntry he[256],
    uint8_t bits[256], uint32_t codes[256])
{
  IACA_START for (i = last; i >= 0; i--)
    {
      codes[i] = code >> (32 - he[i].len);
      bits[i] = he[i].len;
      syms[i] = he[i].sym;
      code += 0x80000000u >> (he[i].len - 1);
     } IACA_END
}
