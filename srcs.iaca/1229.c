#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *str, int outlen, char *out)
{
  int pos = 0;
  for (; *str; str++)
    {
      if (pos + 6 > outlen)
	{
	  char *tmp;
	  outlen = 2 * outlen + 6;
	  tmp = av_realloc (out, outlen + 1);
	  if (!tmp)
	    {
	      av_free (out);
	      return ((void *) 0);
	    }
	  out = tmp;
	}
      if (*str == '&')
	{
	  memcpy (&out[pos], "&amp;", 5);
	  pos += 5;
	}
      else if (*str == '<')
	{
	  memcpy (&out[pos], "&lt;", 4);
	  pos += 4;
	}
      else if (*str == '>')
	{
	  memcpy (&out[pos], "&gt;", 4);
	  pos += 4;
	}
      else if (*str == '\'')
	{
	  memcpy (&out[pos], "&apos;", 6);
	  pos += 6;
	}
      else if (*str == '\"')
	{
	  memcpy (&out[pos], "&quot;", 6);
	  pos += 6;
	}
      else
	{
	  out[pos++] = *str;
	}
    }
}
