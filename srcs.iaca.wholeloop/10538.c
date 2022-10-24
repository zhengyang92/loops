#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef long unsigned int size_t;

int
fn (char *str, uint64_t * opt_block_list, size_t count)
{
  IACA_START for (size_t i = 0; i < count; ++i)
    {
      char *p = strchr (str, ',');
      if (p != ((void *) 0))
	*p = '\0';
      if (str[0] == '\0')
	{
	  ((void) (0));
	  opt_block_list[i] = opt_block_list[i - 1];
	}
      else
	{
	  opt_block_list[i] =
	    str_to_uint64 ("block-list", str, 0, (18446744073709551615UL));
	  if (opt_block_list[i] == 0)
	    {
	      if (i + 1 != count)
		message_fatal (("0 can only be used " "as the last element "
				"in --block-list"));
	      opt_block_list[i] = (18446744073709551615UL);
	    }
	}
      str = p + 1;
     } IACA_END
}
