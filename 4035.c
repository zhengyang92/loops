#include <stdint.h>
#include <stdio.h>






int
fn (const char *const chroma_location_names[7], const char *name, int i)
{
  for (i = 0;
       i <
       (sizeof (chroma_location_names) / sizeof ((chroma_location_names)[0]));
       i++)
    {
      if (!chroma_location_names[i])
	continue;
      if (av_strstart (name, chroma_location_names[i], ((void *) 0)))
	return i;
    }
}
