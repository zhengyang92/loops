#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, char *msg)
{
  for (i = strlen (msg) - 1; i >= 0 && msg[i] == '\n'; i--)
    {
      msg[i] = 0;
    }
}
