#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char mov_mdhd_language_map[139][4], int mp4, int i,
    const char *lang)
{
  IACA_START for (i = 0;
       lang[0] && !mp4
       && i <
       (sizeof (mov_mdhd_language_map) / sizeof ((mov_mdhd_language_map)[0]));
       i++)
    {
      if (!strcmp (lang, mov_mdhd_language_map[i]))
	return i;
     } IACA_END
}
