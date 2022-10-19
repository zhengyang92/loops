#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint32_t uint32_t;
typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (const uint16_t kScan[16], const int16_t * const coeffs, int n,
    uint8_t * const y_dst, uint32_t bits)
{
  for (n = 0; n < 16; ++n, bits <<= 2)
    {
      DoTransform (bits, coeffs + n * 16, y_dst + kScan[n]);
    }
}
