#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int out, int i, unsigned int round, int *coefs, int c, int len, int s)
{
  for (i = 0; i < len; i++)
     { IACA_START
      out = (int) ((int64_t) ((int64_t) coefs[i] * c + round) >> s);
      coefs[i] = -out;
} IACA_END }
