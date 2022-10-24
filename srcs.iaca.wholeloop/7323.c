#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, const char *spherical_projection_names[3], int i)
{
  IACA_START for (i = 0;
       i <
       (sizeof (spherical_projection_names) /
	sizeof ((spherical_projection_names)[0])); i++)
    {
      size_t len = strlen (spherical_projection_names[i]);
      if (!strncmp (spherical_projection_names[i], name, len))
	return i;
     } IACA_END
}
