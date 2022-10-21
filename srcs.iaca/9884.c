#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * const alpha, uint8_t * const ptr, int x, int width,
    int inverse)
{
  for (x = 0; x < width; ++x)
     { IACA_START
      const uint32_t a = alpha[x];
      if (a != 255)
	{
	  if (a == 0)
	    {
	      ptr[x] = 0;
	    }
	  else
	    {
	      const uint32_t scale = GetScale (a, inverse);
	      ptr[x] = Mult (ptr[x], scale);
	}}
} IACA_END }
