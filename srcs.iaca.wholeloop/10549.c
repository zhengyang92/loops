#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned short UInt16;
typedef unsigned int UInt32;
typedef unsigned char UChar;

int
fn (UInt16 s, UInt32 * ftab, UInt32 * ptr, Int32 i, Int32 j, UChar * block)
{
  IACA_START for (; i >= 0; i--)
    {
      s = (s >> 8) | (block[i] << 8);
      j = ftab[s] - 1;
      ftab[s] = j;
      ptr[j] = i;
     } IACA_END
}
