#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (const char *p, int64_t offset)
{
  int in_brackets = 0;
  for (;;)
    {
      if (p[offset] == ' ' || p[offset] == '\t')
	{
	  offset++;
	}
      else if (p[offset] == '[')
	{
	  offset++;
	  in_brackets++;
	}
      else if (p[offset] == ']' && in_brackets)
	{
	  offset++;
	  in_brackets--;
	}
      else if (in_brackets
	       && (p[offset] == ':' || p[offset] == '.' || p[offset] == '-'
		   || (p[offset] >= '0' && p[offset] <= '9')))
	{
	  offset++;
	}
      else
	{
	  break;
	}
    }
}
