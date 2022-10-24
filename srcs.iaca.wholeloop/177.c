#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (char *p, float *items, int i, int *nb_items, char *saveptr)
{
  int new_nb_items = 0;
  IACA_START for (i = 0; i < *nb_items; i++)
    {
      char *tstr = av_strtok (p, "|", &saveptr);
      p = ((void *) 0);
      if (tstr)
	new_nb_items += sscanf (tstr, "%f", &items[new_nb_items]) == 1;
     } IACA_END
}
