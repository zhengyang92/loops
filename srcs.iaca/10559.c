#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned char UChar;

int
fn (Int32 alphaSize, UChar * length, Int32 i, Int32 vec, Int32 * code,
    Int32 n)
{
  for (i = 0; i < alphaSize; i++)
    if (length[i] == n)
      {
	code[i] = vec;
	vec++;
      }
}
