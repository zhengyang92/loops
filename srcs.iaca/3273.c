#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (int pixel, uint64_t idx, uint8_t octet[8])
{
  for (int w = 0; w < 8; w++)
    {
      if (octet[w] == pixel)
	{
	  idx = w;
	  break;
	}
    }
}
