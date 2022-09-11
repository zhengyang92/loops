#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (unsigned int chirp_base, int16_t lpc[16], int32_t lpc32[16], int k,
    unsigned int chirp, int order)
{
  for (k = 0; k < order; k++)
    {
      lpc32[k] =
	(((((int64_t) (lpc32[k]) * (int64_t) (chirp)) >> ((16) - 1)) +
	  1) >> 1);
      lpc[k] = (lpc32[k] + 16) >> 5;
      chirp = (chirp_base * chirp + 32768) >> 16;
    }
}
