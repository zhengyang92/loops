#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (char *arg, int i, int argc, int def, char **argv)
{
  IACA_START for (i = 0; i < argc - 1; ++i)
    {
      if (!argv[i])
	continue;
      if (0 == strcmp (argv[i], arg))
	{
	  def = atoi (argv[i + 1]);
	  del_arg (argc, argv, i);
	  del_arg (argc, argv, i);
	  break;
	}
     } IACA_END
}
