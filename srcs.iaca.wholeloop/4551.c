#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int out, int i, unsigned int round, int c, int len, int *coefs, int s)
{
  IACA_START for (i = 0; i < len; i++)
    {
      out = (int) (((int64_t) coefs[i] * c) >> 32);
      coefs[i] = -((int) (out + round) >> s);
}IACA_END}
