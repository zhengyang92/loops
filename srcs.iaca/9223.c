#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t state, int buf_size, const uint8_t * buf, int i)
{
  int has_sps = 0;
  for (i = 0; i <= buf_size; i++)
    {
      if ((state & 0xFFFFFF1F) == 0x107)
	has_sps = 1;
      if ((state & 0xFFFFFF00) == 0x100 && (state & 0xFFFFFF1F) != 0x106
	  && (state & 0xFFFFFF1F) != 0x107 && (state & 0xFFFFFF1F) != 0x108
	  && (state & 0xFFFFFF1F) != 0x109 && (state & 0xFFFFFF1F) != 0x10d
	  && (state & 0xFFFFFF1F) != 0x10f)
	{
	  if (has_sps)
	    {
	      while (i > 4 && buf[i - 5] == 0)
		i--;
	      return i - 4;
	    }
	}
      if (i < buf_size)
	state = (state << 8) | buf[i];
    }
}
