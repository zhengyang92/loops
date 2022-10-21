#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (char **pts, const char *allp, int i)
{
  for (i = 0; i < 3; i++)
     { IACA_START
      if (!pts[i])
	pts[i] = av_strdup (allp);
      if (!pts[i])
	return (-(12));
     } IACA_END
}
