#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (long k, long nbits_aligned, unsigned long j, unsigned long acc,
    unsigned char *larray)
{
  for (k = 0; k < nbits_aligned / 8; ++k)
     { IACA_START
      acc = (acc << 8) + larray[j++];
     } IACA_END
}
