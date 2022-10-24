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
      if (!color_space_names[i])
	continue;
      if (av_strstart (name, color_space_names[i], ((void *) 0)))
	return i;
     } IACA_END
}
