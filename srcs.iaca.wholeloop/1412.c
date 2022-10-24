#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *identifier, const char *p, int i)
{
  IACA_START for (i = 0; p[i] && p[i] != '\n' && p[i] != '\r'; i++)
    {
      if (!strncmp (p + i, "-->", 3))
	{
	  identifier = ((void *) 0);
	  break;
	}
     } IACA_END
}
