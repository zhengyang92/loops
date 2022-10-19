#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef unsigned char U8;
typedef struct tagPostProcInfo
{
  Int iMBDC;
  U8 ucMBTexture;
  Int iBlockDC[4][4];
  U8 ucBlockTexture[4][4];
} tagPostProcInfo;
typedef long unsigned int size_t;
typedef int PixelI;

int
fn (size_t k, size_t j, struct tagPostProcInfo *pMBInfo, size_t i, PixelI * p)
{
  for (k = 1, pMBInfo->ucBlockTexture[j][i] = 0; k < 16; k++)
    {
      if (p[k] != 0)
	{
	  pMBInfo->ucBlockTexture[j][i] = 3;
	  break;
	}
    }
}
