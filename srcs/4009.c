#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (const int *src2, int i, const int *src1, const int *src0, int *dst,
    int len, int64_t accu)
{
  for (i = 0; i < len; i++)
    {
      accu = (int64_t) src0[i] * src1[i];
      dst[i] = src2[i] + (int) ((accu + 0x40000000) >> 31);
}}