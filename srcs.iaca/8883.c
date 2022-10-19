#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int dsize, const uint8_t * src, int size)
{
  int i = 0;
  for (i = 0; i < size; i++, src++)
    {
      if (src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && i < size - 1
	  && src[1] < 4)
	{
	  dst[dsize++] = src[1];
	  src++;
	  i++;
	}
      else
	dst[dsize++] = *src;
    }
}
