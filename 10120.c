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
typedef int PixelI;
typedef long unsigned int size_t;

int
fn (size_t i, PixelI * pMB, struct tagPostProcInfo *pMBInfo)
{
  for (i = 16; i < 256; i += 16)
    {
      if (pMB[i] != 0)
	{
	  pMBInfo->ucMBTexture = 3;
	  break;
	}
    }
}
