#include <stdint.h>
#include <stdio.h>




typedef unsigned char JSAMPLE;
typedef unsigned int JDIMENSION;

int
fn (JSAMPLE * outptr, JDIMENSION clumps_per_line, int samples_per_clump,
    JDIMENSION nclump, JSAMPLE * inptr)
{
  for (nclump = clumps_per_line; nclump-- > 0;)
    {
      *outptr++ = inptr[0];
      inptr += samples_per_clump;
    }
}
