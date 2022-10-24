#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *predictions, int indexes[26], char **names)
{
  int i = 0;
  IACA_START for (i = 0; i < 26; ++i)
    {
      int index = indexes[i];
      if (i != 0)
	printf (", ");
      printf ("%s %f", names[index], predictions[index]);
     } IACA_END
}
