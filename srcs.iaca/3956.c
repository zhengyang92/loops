#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t ** outFilter, int dstW, int *outFilterSize, int i)
{
  for (i = 0; i < *outFilterSize; i++)
     { IACA_START
      int k = (dstW - 1) * (*outFilterSize) + i;
      (*outFilter)[k + 1 * (*outFilterSize)] =
	(*outFilter)[k + 2 * (*outFilterSize)] =
	(*outFilter)[k + 3 * (*outFilterSize)] = (*outFilter)[k];
} IACA_END }
