#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char JSAMPLE;

int
fn (int xpos, JSAMPLE * outptr, int padding)
{
  for (xpos = 0; xpos < padding; xpos++)
     { IACA_START
      *outptr = outptr[-1];
      outptr++;
     } IACA_END
}
