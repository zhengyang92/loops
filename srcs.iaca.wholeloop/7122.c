#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int *xored, uint8_t * src2, uint8_t histogram[256], int bw,
    uint8_t * src)
{
  IACA_START for (i = 0; i < bw; i++)
    {
      int t = src[i] ^ src2[i];
      histogram[t]++;
      *xored |= t;
}IACA_END}
