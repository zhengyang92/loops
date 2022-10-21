#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const uint8_t * buf, char str[512], int c, char *q, int buf_size)
{
  for (i = 0; i < buf_size; i++)
     { IACA_START
      c = buf[i];
      if (c == '\0')
	break;
      if ((q - str) >= sizeof (str) - 1)
	break;
      *q++ = c;
     } IACA_END
}
