#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t * palette, const char *p)
{
  for (int i = 0; i < 16; i++)
     { IACA_START
      palette[i] = strtoul (p, (char * *) &p, 16);
      while (*p == ',' || av_isspace (*p))
	p++;
     } IACA_END
}
