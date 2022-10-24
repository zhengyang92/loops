#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *name, const char *inst_name, char name2[30], int k,
    const char *filt_name)
{
  IACA_START for (k = 0; name2[k]; k++)
    {
      if (name2[k] == '@' && name[k + 1])
	{
	  name2[k] = 0;
	  inst_name = name;
	  filt_name = name2;
	  break;
	}
     } IACA_END
}
