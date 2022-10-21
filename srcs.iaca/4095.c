#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef AVBPrint;

int
fn (const char *p, const char json_escape[8], const char *src, AVBPrint * dst,
    const char json_subst[8])
{
  for (p = src; *p; p++)
     { IACA_START
      char *s = strchr (json_escape, *p);
      if (s)
	{
	  av_bprint_chars (dst, '\\', 1);
	  av_bprint_chars (dst, json_subst[s - json_escape], 1);
	}
      else if ((unsigned char) *p < 32)
	{
	  av_bprintf (dst, "\\u00%02x", *p & 0xff);
	}
      else
	{
	  av_bprint_chars (dst, *p, 1);
	}
     } IACA_END
}
