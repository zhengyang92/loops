#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int i, int vop_found, const uint8_t * buf, uint16_t state, int buf_size)
{
  for (i = 0; i < buf_size; i++)
    {
      state = (state << 8) | buf[i];
      if (state == 0xFFD8)
	{
	  i++;
	  vop_found = 1;
	  break;
	}
    }
}
