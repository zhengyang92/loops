#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int rc, int fbits, int32_t * row, int k, int j, int32_t * prevrow,
    int gain)
{
  for (j = 0; j < k; j++)
    {
      int x =
	prevrow[j] -
	(((((int64_t) (prevrow[k - j - 1]) * (int64_t) (rc)) >> (31 - 1)) +
	  1) >> 1);
      row[j] =
	(((((int64_t) (x) * (int64_t) (gain)) >> (fbits - 1)) + 1) >> 1);
}}
