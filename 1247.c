#include <stdint.h>
#include <stdio.h>






int
fn (char *res, char *start, int i, char *end)
{
  for (i = 0; res[i]; ++i)
    {
      if (res[i] == '"')
	{
	  if (!start)
	    {
	      start = res + i + 1;
	      continue;
	    }
	  end = res + i;
	  break;
	}
    }
}
