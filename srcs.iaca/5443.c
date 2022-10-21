#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int32_t gv, int32_t gu, int i, int32_t bu, const uint8_t ** src,
    int width, int32_t ru, int32_t bv, uint16_t * dstU, uint16_t * dstV,
    int32_t rv)
{
  for (i = 0; i < width; i++)
     { IACA_START
      int g = src[0][i];
      int b = src[1][i];
      int r = src[2][i];
      dstU[i] = (ru * r + gu * g + bu * b + (0x4001 << (15 - 7))) >> (15 - 6);
      dstV[i] = (rv * r + gv * g + bv * b + (0x4001 << (15 - 7))) >> (15 - 6);
} IACA_END }
