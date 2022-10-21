#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int hasAlpha, const int16_t ** lumSrcPtr, int i, int32_t * lumMmxFilter,
    int16_t * vLumFilter, const int16_t ** alpSrcPtr, int32_t * alpMmxFilter,
    int s, const int vLumFilterSize, int dstY)
{
  for (i = 0; i < vLumFilterSize; i += 2)
     { IACA_START
      *(const void * *) &lumMmxFilter[s * i] = lumSrcPtr[i];
      *(const void * *) &lumMmxFilter[s * i + 8 / 4] =
	lumSrcPtr[i + (vLumFilterSize > 1)];
      lumMmxFilter[s * i + 16 / 4] = lumMmxFilter[s * i + 16 / 4 + 1] =
	vLumFilter[dstY * vLumFilterSize + i] + (vLumFilterSize >
						 1 ? vLumFilter[dstY *
								vLumFilterSize
								+ i +
								1] *
						 (1 << 16) : 0);
      if (1 && hasAlpha)
	{
	  *(const void * *) &alpMmxFilter[s * i] = alpSrcPtr[i];
	  *(const void * *) &alpMmxFilter[s * i + 8 / 4] =
	    alpSrcPtr[i + (vLumFilterSize > 1)];
	  alpMmxFilter[s * i + 16 / 4] = alpMmxFilter[s * i + 16 / 4 + 1] =
	    lumMmxFilter[s * i + 16 / 4];
	}
} IACA_END }
