#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct HuffTable
{
  int xsize;
  const uint8_t *bits;
  const uint16_t *codes;
} HuffTable;
typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int y, uint16_t tmp_codes[512], int x, uint8_t tmp_bits[512], int j,
    int xsize, const HuffTable * h)
{
  IACA_START for (y = 0; y < xsize; y++)
    {
      tmp_bits[(x << 5) | y | ((x && y) << 4)] = h->bits[j];
      tmp_codes[(x << 5) | y | ((x && y) << 4)] = h->codes[j++];
     } IACA_END
}
