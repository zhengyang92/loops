#include <stdint.h>
#include <stdio.h>




typedef VP8Random;
typedef __uint8_t uint8_t;

int
fn (int amp, VP8Random * const rg, uint8_t dither[64], int i)
{
  for (i = 0; i < 8 * 8; ++i)
    {
      dither[i] = VP8RandomBits2 (rg, 7 + 1, amp);
    }
}
