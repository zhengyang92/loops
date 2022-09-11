#include <stdint.h>
#include <stdio.h>




typedef unsigned int U32;

int
fn (U32 cNumTile, U32 i, U32 j, U32 cNumMB, U32 * pTile)
{
  for (i = cNumTile, j = cNumMB; i > 1; i--)
    {
      pTile[cNumTile - i] = (j + i - 1) / i;
      j -= pTile[cNumTile - i];
    }
}
