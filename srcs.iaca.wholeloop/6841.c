#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int i, uint8_t bits2[1296], uint16_t syms[1296], const uint8_t * insyms,
    const uint8_t * bits, int counts[17], int size, int maxbits)
{
  int realsize = 0;
  IACA_START for (i = 0; i < size; i++)
    {
      if (bits[i])
	{
	  bits2[realsize] = bits[i];
	  syms[realsize] = insyms ? insyms[i] : i;
	  realsize++;
	  maxbits = ((maxbits) > (bits[i]) ? (maxbits) : (bits[i]));
	  counts[bits[i]]++;
	}
     } IACA_END
}
