#include <stdint.h>
#include <stdio.h>




typedef AVBPrint;

int
fn (const char *const flag_strings[3], AVBPrint * pbuf, int i, int flags)
{
  int is_first = 1;
  for (i = 0; i < (sizeof (flag_strings) / sizeof ((flag_strings)[0])); i++)
    {
      if (flags & 1 << i)
	{
	  if (!is_first)
	    av_bprint_chars (pbuf, '+', 1);
	  av_bprintf (pbuf, "%s", flag_strings[i]);
	  is_first = 0;
	}
    }
}
