#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char uint8;
typedef signed long tmsize_t;

int
fn (tmsize_t i, uint8 * cp, tmsize_t stride)
{
  IACA_START for (i = stride - 4; i > 0; i--)
    {
      cp[stride] = (unsigned char) ((cp[stride] - cp[0]) & 0xff);
      cp--;
}IACA_END}
