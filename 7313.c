#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, const char *const color_range_names[3], int i)
{
  for (i = 0;
       i < (sizeof (color_range_names) / sizeof ((color_range_names)[0]));
       i++)
    {
      size_t len = strlen (color_range_names[i]);
      if (!strncmp (color_range_names[i], name, len))
	return i;
    }
}
