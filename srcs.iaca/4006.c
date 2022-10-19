#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct error_entry
{
  int num;
  const char *tag;
  const char *str;
} error_entry;

int
fn (const struct error_entry *entry, int errnum,
    const struct error_entry error_entries[28])
{
  int i = 0;
  for (i = 0; i < (sizeof (error_entries) / sizeof ((error_entries)[0])); i++)
    {
      if (errnum == error_entries[i].num)
	{
	  entry = &error_entries[i];
	  break;
	}
    }
}
