#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * pos, const uint8_t * buf, const uint8_t * end, int *pos_p)
{
  for (int i = 0; i < 255 && pos + i + 1 < end; i++)
    {
      if (pos[i] == 'p' && pos[i + 1] == '\0')
	{
	  *pos_p = pos + i - buf;
	  break;
	}
    }
}
