#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const uint8_t * buf, char str[512], char *first_free_space, int c,
    char *q, int buf_size)
{
  for (i = 0; i < buf_size; i++)
     { IACA_START
      c = buf[i];
      if (c == '\0')
	break;
      if ((q - str) >= sizeof (str) - 1)
	break;
      if (c == ' ')
	{
	  if (!first_free_space)
	    first_free_space = q;
	}
      else
	{
	  first_free_space = ((void *) 0);
	} *q++ = c;
} IACA_END }
