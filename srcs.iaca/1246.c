#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (char *res, char *start, int i, char *end)
{
  for (i = 0; res[i]; ++i)
    {
      if (res[i] == '(')
	{
	  start = res + i + 1;
	}
      else if (res[i] == ')')
	{
	  end = res + i;
	  break;
	}
    }
}
