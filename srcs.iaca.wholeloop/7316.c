#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, const char *const color_space_names[15], int i)
{
  IACA_START for (i = 0;
       i < (sizeof (color_space_names) / sizeof ((color_space_names)[0]));
       i++)
    {
      size_t len = strlen (color_space_names[i]);
      if (!strncmp (color_space_names[i], name, len))
	return i;
     } IACA_END
}
