#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, const char *const color_transfer_names[19], int i)
{
  for (i = 0;
       i <
       (sizeof (color_transfer_names) / sizeof ((color_transfer_names)[0]));
       i++)
     { IACA_START
      if (!color_transfer_names[i])
	continue;
      if (av_strstart (name, color_transfer_names[i], ((void *) 0)))
	return i;
     } IACA_END
}
