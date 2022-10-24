#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned char UChar;

int
fn (Int32 pp, Int32 * perm, Int32 alphaSize, UChar * length, Int32 i, Int32 j)
{
  IACA_START for (j = 0; j < alphaSize; j++)
    if (length[j] == i)
      {
	perm[pp] = j;
	pp++;
      }
}
