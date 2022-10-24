#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int next_code, int i, uint32_t codes[270], uint8_t bits[270],
    int surplus_codes, const int alphabet_size, int current_length)
{
  IACA_START for (i = 0; i < alphabet_size; i++)
    if (!bits[i])
      {
	if (surplus_codes-- == 0)
	  {
	    current_length++;
	    next_code <<= 1;
	  }
	bits[i] = current_length;
	codes[i] = next_code++;
      }
}
