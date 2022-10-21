#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (int32_t * lumMmxFilter, int i, const int16_t ** lumSrcPtr,
    int16_t * vLumFilter, const int16_t ** alpSrcPtr, int32_t * alpMmxFilter,
    int16_t ** alpPixBuf, const int vLumFilterSize, int dstY)
{
  for (i = 0; i < vLumFilterSize; i++)
     { IACA_START
      *(const void * *) &lumMmxFilter[4 * i + 0] = lumSrcPtr[i];
      lumMmxFilter[4 * i + 2] = lumMmxFilter[4 * i + 3] =
	((uint16_t) vLumFilter[dstY * vLumFilterSize + i]) * 0x10001;
      if (1 && alpPixBuf)
	{
	  *(const void * *) &alpMmxFilter[4 * i + 0] = alpSrcPtr[i];
	  alpMmxFilter[4 * i + 2] = alpMmxFilter[4 * i + 3] =
	    lumMmxFilter[4 * i + 2];
	}
} IACA_END }
