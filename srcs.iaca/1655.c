#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (long k, unsigned long j, long nbits_aligned, unsigned long acc,
    unsigned char *larray)
{
  for (k = 0; k < nbits_aligned / 8; ++k)
    {
      acc = (acc << 8) + larray[j++];
    }
}
