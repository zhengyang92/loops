#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;

int
fn (unsigned char *cp, tmsize_t i, tmsize_t stride)
{
  IACA_START for (i = stride - 4; i > 0; i--)
    {
      cp[stride] = (unsigned char) ((cp[stride] - cp[0]) & 0xff);
      cp--;
}IACA_END}
