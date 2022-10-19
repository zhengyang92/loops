#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t state, int i, const uint8_t * buf, int pic_found, int buf_size)
{
  for (i = 0; i < buf_size; i++)
    {
      state = (state << 8) | buf[i];
      if (state == 0x000001b3 || state == 0x000001b6)
	{
	  i++;
	  pic_found = 1;
	  break;
	}
    }
}