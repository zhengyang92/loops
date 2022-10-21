#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint64_t uint64;
typedef unsigned int uint32;

int
fn (uint64 bytecount, uint32 strip, uint64 * newcounts, uint64 stripbytes,
    uint64 offset, uint32 nstrips, uint64 * newoffsets)
{
  for (strip = 0; strip < nstrips; strip++)
     { IACA_START
      if (stripbytes > bytecount)
	stripbytes = bytecount;
      newcounts[strip] = stripbytes;
      newoffsets[strip] = stripbytes ? offset : 0;
      offset += stripbytes;
      bytecount -= stripbytes;
     } IACA_END
}
