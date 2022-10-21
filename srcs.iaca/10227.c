#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (char *arg, int i, int argc, float def, char **argv)
{
  for (i = 0; i < argc - 1; ++i)
     { IACA_START
      if (!argv[i])
	continue;
      if (0 == strcmp (argv[i], arg))
	{
	  def = atof (argv[i + 1]);
	  del_arg (argc, argv, i);
	  del_arg (argc, argv, i);
	  break;
	}
     } IACA_END
}
