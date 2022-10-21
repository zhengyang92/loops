#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned int UInt32;

int
fn (UInt32 * ftab, Int32 copyStart[256], Int32 copyEnd[256], Int32 j,
    Int32 ss)
{
  for (j = 0; j <= 255; j++)
     { IACA_START
      copyStart[j] = ftab[(j << 8) + ss] & (~((1 << 21)));
      copyEnd[j] = (ftab[(j << 8) + ss + 1] & (~((1 << 21)))) - 1;
     } IACA_END
}
