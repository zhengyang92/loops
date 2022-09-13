#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, const char *const color_transfer_names[19], int i)
{
  for (i = 0;
       i <
       (sizeof (color_transfer_names) / sizeof ((color_transfer_names)[0]));
       i++)
    {
      size_t len = strlen (color_transfer_names[i]);
      if (!strncmp (color_transfer_names[i], name, len))
	return i;
    }
}
