#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, const char *const color_primaries_names[23], int i)
{
  IACA_START for (i = 0;
       i <
       (sizeof (color_primaries_names) / sizeof ((color_primaries_names)[0]));
       i++)
    {
      size_t len = strlen (color_primaries_names[i]);
      if (!strncmp (color_primaries_names[i], name, len))
	return i;
     } IACA_END
}
