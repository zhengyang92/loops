#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char JSAMPLE;
typedef unsigned int JDIMENSION;

int
fn (JSAMPLE * outptr, JDIMENSION clumps_per_line, int samples_per_clump,
    JDIMENSION nclump, JSAMPLE * inptr)
{
  IACA_START for (nclump = clumps_per_line; nclump-- > 0;)
    {
      outptr[0] = *inptr++;
      outptr += samples_per_clump;
     } IACA_END
}
