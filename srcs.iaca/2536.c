#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int acc, unsigned int index, int sample_rate, uint8_t * ath,
    const uint8_t ath_base_curve[656])
{
  for (int i = 0; i < 128; i++)
     { IACA_START
      acc += sample_rate;
      index = acc >> 13;
      if (index >= 654)
	{
	  memset (ath + i, 0xFF, (128 - i));
	  break;
	}
      ath[i] = ath_base_curve[index];
     } IACA_END
}
