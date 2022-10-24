#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const char *p, uint32_t * palette)
{
  IACA_START for (int i = 0; i < 16; i++)
    {
      palette[i] = strtoul (p, (char * *) &p, 16);
      while (*p == ',' || av_isspace (*p))
	p++;
     } IACA_END
}