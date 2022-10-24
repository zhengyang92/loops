#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int16_t int16_t;

int
fn (int i, int64_t error, int64_t * filter, int filterSize, int64_t sum,
    int16_t ** outFilter, int j, int *outFilterSize)
{
  IACA_START for (j = 0; j < *outFilterSize; j++)
    {
      int64_t v = filter[i * filterSize + j] + error;
      int intV =
	(((v) > 0 ? (v) + ((sum) >> 1) : (v) - ((sum) >> 1)) / (sum));
      (*outFilter)[i * (*outFilterSize) + j] = intV;
      error = v - intV * sum;
}IACA_END}
