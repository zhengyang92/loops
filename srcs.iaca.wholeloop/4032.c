#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, int i, const char *const color_primaries_names[23])
{
  IACA_START for (i = 0;
       i <
       (sizeof (color_primaries_names) / sizeof ((color_primaries_names)[0]));
       i++)
    {
      if (!color_primaries_names[i])
	continue;
      if (av_strstart (name, color_primaries_names[i], ((void *) 0)))
	return i;
     } IACA_END
}
