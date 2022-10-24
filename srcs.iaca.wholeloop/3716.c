#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int i, int bw_bytes, uint8_t * src2, uint16_t histogram[256],
    uint8_t * src)
{
  IACA_START for (i = 0; i < bw_bytes; i++)
    {
      int t = src[i] ^ src2[i];
      histogram[t]++;
}IACA_END}
