#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef AVBPrint;

int
fn (const char *p, const char *linebreaks, const char *p_end,
    int keep_ass_markup, AVBPrint * buf)
{
  for (; p < p_end && *p; p++)
    {
      if (linebreaks && strchr (linebreaks, *p))
	{
	  av_bprintf (buf, "\\N");
	}
      else if (!keep_ass_markup && strchr ("{}\\", *p))
	{
	  av_bprintf (buf, "\\%c", *p);
	}
      else if (p[0] == '\n')
	{
	  if (p < p_end - 1)
	    av_bprintf (buf, "\\N");
	}
      else if (p[0] == '\r' && p < p_end - 1 && p[1] == '\n')
	{
	  continue;
	}
      else
	{
	  av_bprint_chars (buf, *p, 1);
	}
    }
}
