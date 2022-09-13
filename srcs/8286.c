#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int hasAlpha, const int16_t ** lumSrcPtr, int i, int32_t * lumMmxFilter,
    int16_t * vLumFilter, const int16_t ** alpSrcPtr, int32_t * alpMmxFilter,
    const int vLumFilterSize, int dstY)
{
  for (i = 0; i < vLumFilterSize; i++)
    {
      *(const void * *) &lumMmxFilter[4 * i + 0] = lumSrcPtr[i];
      lumMmxFilter[4 * i + 2] = lumMmxFilter[4 * i + 3] =
	((uint16_t) vLumFilter[dstY * vLumFilterSize + i]) * 0x10001U;
      if (1 && hasAlpha)
	{
	  *(const void * *) &alpMmxFilter[4 * i + 0] = alpSrcPtr[i];
	  alpMmxFilter[4 * i + 2] = alpMmxFilter[4 * i + 3] =
	    lumMmxFilter[4 * i + 2];
	}
}}
