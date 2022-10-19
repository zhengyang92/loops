#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int count, int i, uint16_t * out, int inp_off, uint16_t * inp, int outcnt)
{
  for (i = inp_off; i < count + inp_off; i++)
    {
      out[outcnt++] = inp[i];
    }
}
