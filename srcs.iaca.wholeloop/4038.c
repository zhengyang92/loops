#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, const char *const spherical_projection_names[3], int i)
{
  IACA_START for (i = 0;
       i <
       (sizeof (spherical_projection_names) /
	sizeof ((spherical_projection_names)[0])); i++)
    {
      if (av_strstart (name, spherical_projection_names[i], ((void *) 0)))
	return i;
     } IACA_END
}
