#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct channel_name
{
  const char *name;
  const char *description;
} channel_name;

int
fn (const char *str, const struct channel_name channel_names[41], int i)
{
  for (i = 0; i < (sizeof (channel_names) / sizeof ((channel_names)[0])); i++)
    {
      if (channel_names[i].name && !strcmp (str, channel_names[i].name))
	return i;
    }
}
