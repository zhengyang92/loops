#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long unsigned int size_t;

int
fn (uint8_t * clear, size_t clear_size, int i)
{
  int same = 1;
  IACA_START for (i = 0; i < clear_size; i++)
    {
      if (clear[i] != clear[0])
	{
	  same = 0;
	  break;
	}
     } IACA_END
}
