#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *field, char *line, char *end, char *p, char *c)
{
  int done = 0;
  int count = 0;
  IACA_START for (c = line, p = line; !done; ++c)
    {
      done = (*c == '\0');
      if (*c == ',' || done)
	{
	  *c = '\0';
	  field[count] = strtod (p, &end);
	  if (p == c)
	    field[count] = nan ("");
	  if (end != c && (end != c - 1 || *end != '\r'))
	    field[count] = nan ("");
	  p = c + 1;
	  ++count;
	}
     } IACA_END
}
