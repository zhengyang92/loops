#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const char *p, int v, int c, int len, uint8_t * data)
{
  for (;;)
    {
      p += strspn (p, " \t\r\n");
      if (*p == '\0')
	break;
      c = av_toupper ((unsigned char) *p++);
      if (c >= '0' && c <= '9')
	c = c - '0';
      else if (c >= 'A' && c <= 'F')
	c = c - 'A' + 10;
      else
	break;
      v = (v << 4) | c;
      if (v & 0x100)
	{
	  if (data)
	    data[len] = v;
	  len++;
	  v = 1;
	}
    }
}
