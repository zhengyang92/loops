#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t state, int i, int vop_found, const uint8_t * buf, int buf_size)
{
  for (i = 0; i < buf_size; i++)
    {
      state = (state << 8) | buf[i];
      if (state >> (32 - 22) == 0x20)
	{
	  i++;
	  vop_found = 1;
	  break;
	}
    }
}
