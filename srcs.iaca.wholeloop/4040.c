#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *const stereo3d_type_names[8], const char *name, int i)
{
  IACA_START for (i = 0;
       i < (sizeof (stereo3d_type_names) / sizeof ((stereo3d_type_names)[0]));
       i++)
    {
      if (av_strstart (name, stereo3d_type_names[i], ((void *) 0)))
	return i;
     } IACA_END
}
