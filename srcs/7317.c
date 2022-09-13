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
      size_t len = strlen (chroma_location_names[i]);
      if (!strncmp (chroma_location_names[i], name, len))
	return i;
    }
}
