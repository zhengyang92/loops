#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *tagname, int likely_a_tag, int i)
{
  for (i = 0; tagname[i]; i++)
    {
      if (!
	  (((tagname[i]) >= '0' && (tagname[i]) <= '9')
	   || ((tagname[i]) >= 'a' && (tagname[i]) <= 'z')
	   || ((tagname[i]) >= 'A' && (tagname[i]) <= 'Z')
	   || (tagname[i]) == '_' || (tagname[i]) == '/'))
	{
	  likely_a_tag = 0;
	  break;
	}
    }
}
