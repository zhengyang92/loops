#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;

int
fn (Int32 * limit, Int32 * base, Int32 minLen, Int32 vec, Int32 i,
    Int32 maxLen)
{
  for (i = minLen; i <= maxLen; i++)
     { IACA_START
      vec += (base[i + 1] - base[i]);
      limit[i] = vec - 1;
      vec <<= 1;
     } IACA_END
}
