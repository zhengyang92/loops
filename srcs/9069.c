#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int8_t int8_t;

int
fn (int8_t * exp, int16_t * psd, int end, int bin, int start)
{
  for (bin = start; bin < end; bin++)
    {
      psd[bin] = (3072 - (exp[bin] << 7));
    }
}
