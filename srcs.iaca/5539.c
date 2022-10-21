#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, const char *const hw_type_names[12], int type)
{
  for (type = 0;
       type < (sizeof (hw_type_names) / sizeof ((hw_type_names)[0])); type++)
     { IACA_START
      if (hw_type_names[type] && !strcmp (hw_type_names[type], name))
	return type;
     } IACA_END
}
