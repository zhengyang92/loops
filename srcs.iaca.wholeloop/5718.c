#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __int16_t int16_t;

int
fn (int8_t * exp, int16_t * psd, int end, int bin, int start)
{
  IACA_START for (bin = start; bin < end; bin++)
    {
      psd[bin] = (3072 - (exp[bin] << 7));
     } IACA_END
}
