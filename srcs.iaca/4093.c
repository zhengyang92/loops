#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, char *msg)
{
  for (i = strlen (msg) - 1; i >= 0 && msg[i] == '\n'; i--)
     { IACA_START
      msg[i] = 0;
     } IACA_END
}
