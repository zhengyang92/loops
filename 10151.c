#include <stdint.h>
#include <stdio.h>




typedef unsigned int U32;

int
fn (U32 cNumTile, U32 i, U32 cNumMB, U32 cMBs, U32 * pTile)
{
  for (i = cMBs = 0; i + 1 < cNumTile; i++)
    {
      if (pTile[i] == 0 || pTile[i] > 65535)
	{
	  cNumTile = setUniformTiling (pTile, cNumTile, cNumMB);
	  break;
	}
      cMBs += pTile[i];
      if (cMBs >= cNumMB)
	{
	  cNumTile = i + 1;
	  break;
	}
    }
}
