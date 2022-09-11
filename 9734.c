#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (int32_t * lumMmxFilter, const int16_t ** lumSrcPtr, int i,
    int16_t * vLumFilter, const int16_t ** alpSrcPtr, int32_t * alpMmxFilter,
    int s, int16_t ** alpPixBuf, const int vLumFilterSize, int dstY)
{
  for (i = 0; i < vLumFilterSize; i += 2)
    {
      *(const void * *) &lumMmxFilter[s * i] = lumSrcPtr[i];
      *(const void * *) &lumMmxFilter[s * i + 8 / 4] =
	lumSrcPtr[i + (vLumFilterSize > 1)];
      lumMmxFilter[s * i + 16 / 4] = lumMmxFilter[s * i + 16 / 4 + 1] =
	vLumFilter[dstY * vLumFilterSize + i] + (vLumFilterSize >
						 1 ? vLumFilter[dstY *
								vLumFilterSize
								+ i +
								1] << 16 : 0);
      if (1 && alpPixBuf)
	{
	  *(const void * *) &alpMmxFilter[s * i] = alpSrcPtr[i];
	  *(const void * *) &alpMmxFilter[s * i + 8 / 4] =
	    alpSrcPtr[i + (vLumFilterSize > 1)];
	  alpMmxFilter[s * i + 16 / 4] = alpMmxFilter[s * i + 16 / 4 + 1] =
	    lumMmxFilter[s * i + 16 / 4];
	}
}}
