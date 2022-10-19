#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int argc, char *arg, char **argv, int i)
{
  for (i = 0; i < argc; ++i)
    {
      if (!argv[i])
	continue;
      if (0 == strcmp (argv[i], arg))
	{
	  del_arg (argc, argv, i);
	  return 1;
	}
    }
}
