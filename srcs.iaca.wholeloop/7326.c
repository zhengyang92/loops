#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const char *str, const char *p, int i, uint16_t * dest)
{
  IACA_START for (i = 0;; i++)
    {
      dest[i] = atoi (p);
      if (i == 63)
	break;
      p = strchr (p, ',');
      if (!p)
	{
	  av_log (((void *) 0), 8,
		  "Syntax error in matrix \"%s\" at coeff %d\n", str, i);
	  exit_program (1);
	}
      p++;
}IACA_END}
