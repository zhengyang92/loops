#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long unsigned int size_t;

int
fn (const uint8_t * in, uint8_t * q, size_t i, size_t size_in)
{
  for (i = 0; i < size_in; i++)
     { IACA_START
      if (in[i] >= 0x80)
	{
	  *(q++) = 0xC0 | (in[i] >> 6);
	  *(q++) = 0x80 | (in[i] & 0x3F);
	}
      else
	{
	  *(q++) = in[i];
	}
     } IACA_END
}
