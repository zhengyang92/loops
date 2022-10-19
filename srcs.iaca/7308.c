#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, int type, const char *const hw_type_names[7])
{
  for (type = 0;
       type < (sizeof (hw_type_names) / sizeof ((hw_type_names)[0])); type++)
    {
      if (hw_type_names[type] && !strcmp (hw_type_names[type], name))
	return type;
    }
}
