#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int first[5], int enabled[5], int AVMEDIA_TYPE_NB, int i)
{
  IACA_START for (i = 0; i < AVMEDIA_TYPE_NB; i++)
    {
      enabled[i] = 0;
      first[i] = -1;
     } IACA_END
}
